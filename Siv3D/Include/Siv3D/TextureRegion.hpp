﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2017 Ryo Suzuki
//	Copyright (c) 2016-2017 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# pragma once
# include "Fwd.hpp"
# include "Texture.hpp"
# include "FloatRect.hpp"

namespace s3d
{
	struct TextureRegion
	{
		Texture texture;

		FloatRect uvRect;

		Float2 size;

		TextureRegion() = default;

		TextureRegion(const Texture& _texture)
			: texture(_texture)
			, uvRect(0.0f, 0.0f, 1.0f, 1.0f)
			, size(_texture.size()) {}

		TextureRegion(
			const Texture& _texture,
			float l,
			float t,
			float r,
			float b,
			double sx,
			double sy
		)
			: texture(_texture)
			, uvRect(l, t, r, b)
			, size(sx, sy) {}

		TextureRegion(
			const Texture& _texture,
			float l,
			float t,
			float r,
			float b,
			const Vec2& _size
		)
			: texture(_texture)
			, uvRect(l, t, r, b)
			, size(_size) {}

		TextureRegion(
			const Texture& _texture,
			const FloatRect& _uvRect,
			double sx,
			double sy
		)
			: texture(_texture)
			, uvRect(_uvRect)
			, size(sx, sy) {}

		TextureRegion(
			const Texture& _texture,
			const FloatRect& _uvRect,
			const Vec2& _size
		)
			: texture(_texture)
			, uvRect(_uvRect)
			, size(_size) {}

		RectF region(double x, double y) const
		{
			return{ x, y, size };
		}

		RectF region(const Vec2& pos = Vec2(0, 0)) const
		{
			return region(pos.x, pos.y);
		}

		RectF regionAt(double x, double y) const
		{
			return{ x - size.x * 0.5, y - size.y * 0.5, size };
		}

		RectF regionAt(const Vec2& pos) const
		{
			return regionAt(pos.x, pos.y);
		}

		/// <summary>
		/// テクスチャを描きます。
		/// </summary>
		/// <param name="diffuse">
		/// 乗算する色
		/// </param>
		/// <returns>
		/// 描画領域
		/// </returns>
		RectF draw(const ColorF& diffuse = Palette::White) const;

		/// <summary>
		/// 指定した位置にテクスチャを描きます。
		/// </summary>
		/// <param name="x">
		/// 描画開始位置の X 座標
		/// </param>
		/// <param name="y">
		/// 描画開始位置の Y 座標
		/// </param>
		/// <param name="diffuse">
		/// 乗算する色
		/// </param>
		/// <returns>
		/// 描画領域
		/// </returns>
		RectF draw(double x, double y, const ColorF& diffuse = Palette::White) const;

		/// <summary>
		/// 指定した位置にテクスチャを描きます。
		/// </summary>
		/// <param name="pos">
		/// 描画開始位置
		/// </param>
		/// <param name="diffuse">
		/// 乗算する色
		/// </param>
		/// <returns>
		/// 描画領域
		/// </returns>
		RectF draw(const Vec2& pos, const ColorF& diffuse = Palette::White) const;

		/// <summary>
		/// 中心位置を指定してテクスチャを描きます。
		/// </summary>
		/// <param name="x">
		/// 中心位置の X 座標
		/// </param>
		/// <param name="y">
		/// 中心位置の X 座標
		/// </param>
		/// <param name="diffuse">
		/// 乗算する色
		/// </param>
		/// <returns>
		/// 描画領域
		/// </returns>
		RectF drawAt(double x, double y, const ColorF& diffuse = Palette::White) const;

		/// <summary>
		/// 中心位置を指定してテクスチャを描きます。
		/// </summary>
		/// <param name="pos">
		/// 中心位置の座標
		/// </param>
		/// <param name="diffuse">
		/// 乗算する色
		/// </param>
		/// <returns>
		/// 描画領域
		/// </returns>
		RectF drawAt(const Vec2& pos, const ColorF& diffuse = Palette::White) const;

		TextureRegion mirror() const;

		TextureRegion flip() const;

		TextureRegion scale(double scaling) const;

		TextureRegion scale(double xScaling, double yScaling) const;

		TextureRegion scale(const Vec2& scaling) const;

		TextureRegion resize(double width, double height) const;

		TextureRegion resize(const Vec2& _size) const;

		//TexturedQuad rotate(double radian) const;

		//TexturedQuad rotateAt(double x, double y, double radian) const;

		//TexturedQuad rotateAt(const Vec2& pos, double radian) const;
	};
}
