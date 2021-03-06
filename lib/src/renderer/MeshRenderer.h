/*
* Viry3D
* Copyright 2014-2017 by Stack - stackos@qq.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#pragma once

#include "Renderer.h"
#include "graphics/Mesh.h"

namespace Viry3D
{
	class MeshRenderer: public Renderer
	{
		DECLARE_COM_CLASS(MeshRenderer, Renderer);
	public:
		virtual const VertexBuffer* GetVertexBuffer() const;
		virtual const IndexBuffer* GetIndexBuffer() const;
		virtual void GetIndexRange(int material_index, int& start, int& count) const;
		virtual bool IsValidPass(int material_index) const;
		const Ref<Mesh>& GetSharedMesh() const { return m_mesh; }
		void SetSharedMesh(const Ref<Mesh>& mesh) { m_mesh = mesh; }

	private:
		MeshRenderer();

	private:
		Ref<Mesh> m_mesh;
	};
}
