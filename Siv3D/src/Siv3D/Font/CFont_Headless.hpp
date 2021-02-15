﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2021 Ryo Suzuki
//	Copyright (c) 2016-2021 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# pragma once
# include <Siv3D/Common.hpp>
# include <Siv3D/Font.hpp>
# include <Siv3D/AssetHandleManager/AssetHandleManager.hpp>
# include "IFont.hpp"
# include "FontData.hpp"

namespace s3d
{
	class CFont_Headless final : public ISiv3DFont
	{
	private:

		FT_Library m_freeType = nullptr;

		AssetHandleManager<Font::IDType, FontData> m_fonts{ U"Font" };

	public:

		CFont_Headless();

		~CFont_Headless();

		void init() override;

		Font::IDType create(FilePathView path, size_t faceIndex, FontMethod fontMethod, int32 fontSize, FontStyle style) override;

		Font::IDType create(Typeface typeface, FontMethod fontMethod, int32 fontSize, FontStyle style) override;

		void release(Font::IDType handleID) override;

		bool addFallbackFont(Font::IDType handleID, const std::weak_ptr<AssetHandle<Font>::AssetIDWrapperType>& font) override;

		const FontFaceProperty& getProperty(Font::IDType handleID) override;

		FontMethod getMethod(Font::IDType handleID) override;

		void setBufferThickness(Font::IDType handleID, int32 thickness) override;

		int32 getBufferThickness(Font::IDType handleID) override;

		bool hasGlyph(Font::IDType handleID, StringView ch) override;

		GlyphIndex getGlyphIndex(Font::IDType handleID, StringView ch) override;

		Array<GlyphCluster> getGlyphClusters(Font::IDType handleID, StringView s, bool recursive) override;

		GlyphInfo getGlyphInfo(Font::IDType handleID, StringView ch) override;

		OutlineGlyph renderOutline(Font::IDType handleID, StringView ch, CloseRing closeRing) override;

		OutlineGlyph renderOutlineByGlyphIndex(Font::IDType handleID, GlyphIndex glyphIndex, CloseRing closeRing) override;

		Array<OutlineGlyph> renderOutlines(Font::IDType handleID, StringView s, CloseRing closeRing) override;

		BitmapGlyph renderBitmap(Font::IDType handleID, StringView s) override;

		BitmapGlyph renderBitmapByGlyphIndex(Font::IDType handleID, GlyphIndex glyphIndex) override;

		SDFGlyph renderSDF(Font::IDType handleID, StringView s, int32 buffer) override;

		SDFGlyph renderSDFByGlyphIndex(Font::IDType handleID, GlyphIndex glyphIndex, int32 buffer) override;

		MSDFGlyph renderMSDF(Font::IDType handleID, StringView s, int32 buffer) override;

		MSDFGlyph renderMSDFByGlyphIndex(Font::IDType handleID, GlyphIndex glyphIndex, int32 buffer) override;
	
		bool preload(Font::IDType handleID, StringView chars) override;

		const Texture& getTexture(Font::IDType handleID) override;

		RectF region(Font::IDType handleID, StringView s, const Array<GlyphCluster>& clusters, const Vec2& pos, double fontSize, double lineHeightScale) override;

		RectF regionBase(Font::IDType handleID, StringView s, const Array<GlyphCluster>& clusters, const Vec2& pos, double fontSize, double lineHeightScale) override;

		RectF draw(Font::IDType handleID, StringView s, const Array<GlyphCluster>& clusters, const Vec2& pos, double fontSize, const TextStyle& textStyle, const ColorF& color, double lineHeightScale) override;

		RectF drawBase(Font::IDType handleID, StringView s, const Array<GlyphCluster>& clusters, const Vec2& pos, double fontSize, const TextStyle& textStyle, const ColorF& color, double lineHeightScale) override;
	
		RectF drawFallback(Font::IDType handleID, StringView s, const GlyphCluster& cluster, const Vec2& pos, double fontSize, const TextStyle& textStyle, const ColorF& color, double lineHeightScale) override;

		RectF drawBaseFallback(Font::IDType handleID, StringView s, const GlyphCluster& cluster, const Vec2& pos, double fontSize, const TextStyle& textStyle, const ColorF& color, double lineHeightScale) override;

		RectF regionFallback(Font::IDType handleID, StringView s, const GlyphCluster& cluster, const Vec2& pos, double fontSize, double lineHeightScale) override;

		RectF regionBaseFallback(Font::IDType handleID, StringView s, const GlyphCluster& cluster, const Vec2& pos, double fontSize, double lineHeightScale) override;
	};
}