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

#include "UIView.h"
#include "Font.h"

namespace Viry3D
{
	enum class FontStyle
	{
		Normal,
		Bold,
		Italic,
		BoldAndItalic
	};

	enum class TextAlignment
	{
		UpperLeft,
		UpperCenter,
		UpperRight,
		MiddleLeft,
		MiddleCenter,
		MiddleRight,
		LowerLeft,
		LowerCenter,
		LowerRight
	};

	struct LabelLine
	{
		int width;
		int height;
		Vector<Vector2> vertices;
		Vector<Vector2> uv;
		Vector<Color> colors;
		Vector<unsigned short> indices;

		void Clear()
		{
			vertices.Clear();
			uv.Clear();
			colors.Clear();
			indices.Clear();
		}
	};

	//
	//	Supported rich tags
	//
	//	<color=#ffffffff></color>
	//	<shadow></shadow>
	//	<shadow=#000000ff></shadow>
	//	<outline></outline>
	//	<outline=#000000ff></outline>
	//	<underline></underline>
	//	<bold></bold>������
	//	<italic></italic>��б��
	//
	class UILabel: public UIView
	{
		DECLARE_COM_CLASS(UILabel, UIView);
	public:
		void SetFont(const Ref<Font>& font);
		void SetFontStyle(FontStyle style);
		void SetFontSize(int size);
		void SetText(const String& text);
		void SetLineSpace(int space);
		void SetRich(bool rich);
		void SetAlignment(TextAlignment alignment);

		virtual void FillVertices(Vector<Vector3>& vertices, Vector<Vector2>& uv, Vector<Color>& colors, Vector<unsigned short>& indices);
		virtual void FillMaterial(Ref<Material>& mat);

	protected:
		UILabel();
		Vector<LabelLine> ProcessText(int& actual_width, int& actual_height);

		Ref<Font> m_font;
		FontStyle m_font_style;
		int m_font_size;
		String m_text;
		int m_line_space;
		bool m_rich;
		TextAlignment m_alignment;
	};
}
