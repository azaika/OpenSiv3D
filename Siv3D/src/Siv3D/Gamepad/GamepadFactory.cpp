//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2018 Ryo Suzuki
//	Copyright (c) 2016-2018 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# include "CGamepad_Windows.hpp"
# include "CGamepad_macOS.hpp"
# include "CGamepad_Linux.hpp"

namespace s3d
{
	ISiv3DGamepad* ISiv3DGamepad::Create()
	{
		return new CGamepad;
	}
}

