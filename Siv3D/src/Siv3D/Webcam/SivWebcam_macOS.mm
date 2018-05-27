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

# include <string>
# include <vector>
# import <AVFoundation/AVFoundation.h>

struct macOS_WebcamInfo
{
	unsigned index;
	
	std::string name;
	
	std::string uniqueName;
};

std::vector<macOS_WebcamInfo> macOS_EnumerateWebcam()
{
	NSAutoreleasePool* localpool = [[NSAutoreleasePool alloc] init];

	NSArray* devices = [[AVCaptureDevice devicesWithMediaType: AVMediaTypeVideo]
						arrayByAddingObjectsFromArray:[AVCaptureDevice devicesWithMediaType:AVMediaTypeMuxed]];
	
	std::vector<macOS_WebcamInfo> results;
	
	for (unsigned index = 0; index < devices.count; ++index)
	{
		AVCaptureDevice* captureDevice = devices[index];
		
		if (!captureDevice)
		{
			continue;
		}
		
		macOS_WebcamInfo info;
		info.index = index;
		info.name = [[captureDevice localizedName] UTF8String];
		info.uniqueName = [[captureDevice uniqueID] UTF8String];
		
		results.push_back(info);
	}
	
	[localpool drain];
	return results;
}
