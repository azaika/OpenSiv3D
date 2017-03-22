﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (C) 2008-2017 Ryo Suzuki
//	Copyright (C) 2016-2017 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# pragma once

#ifdef __cplusplus

extern "C"
{

#endif
	
	void s3d_DraggingEntered(bool isFilePath);
	
	void s3d_DraggingUpdated();

	void s3d_DraggingExited();
	
	void s3d_DataDropped(const char* text);
	
#ifdef __cplusplus

}

#endif
