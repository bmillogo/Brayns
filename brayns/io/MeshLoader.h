/* Copyright (c) 2015-2016, EPFL/Blue Brain Project
 * All rights reserved. Do not distribute without permission.
 * Responsible Author: Cyrille Favreau <cyrille.favreau@epfl.ch>
 *
 * This file is part of Brayns <https://github.com/BlueBrain/Brayns>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef MESHLOADER_H
#define MESHLOADER_H

#include <brayns/common/types.h>
#include <brayns/common/material/Material.h>
#include <brayns/common/material/Texture2D.h>
#include <brayns/common/geometry/TrianglesMesh.h>
#include <brayns/parameters/GeometryParameters.h>

#include <string>

class aiScene;

namespace brayns
{

/** Loads meshes from files using the assimp library
 * http://assimp.sourceforge.net
 */
class MeshLoader
{
public:
    MeshLoader();

    /** Imports meshes from a given file
     *
     * @param filename name of the file containing the meshes
     * @param Scene holding the meshes
     * @param meshQuality can be MQ_FAST, MQ_QUALITY or MQ_MAX_QUALITY. Appart
     *        from MQ_FAST, normals are automatically generated is not in the
     *        file.
     * @param position where to position the imported mesh
     * @param scale how to scale the imported mesh
     * @param defaultMaterial Default material for the whole mesh. If set to
     *        NO_MATERIAL, materials from the mesh file are used. Otherwise,
     *        all meshes are forced to that specific material.
     * @return true if the file was successfully imported. False otherwise.
     */
    bool importMeshFromFile(
            const std::string& filename,
            Scene& scene,
            MeshQuality meshQuality,
            const Vector3f& position,
            const Vector3f& scale,
            const size_t defaultMaterial);

    /** Exports meshes to a given file
     *
     * @param filename destination file name
     * @param Scene holding the meshes
     */
    bool exportMeshToFile(
            const std::string& filename,
            Scene& scene ) const;

    /**
     * @brief Clear all internal buffers
     */
    void clear();

private:

    void _createMaterials(
        Scene& scene,
        const aiScene *aiScene,
        const std::string& folder );

    std::map<size_t, size_t> _meshIndex;
};

}

#endif // MESHLOADER_H
