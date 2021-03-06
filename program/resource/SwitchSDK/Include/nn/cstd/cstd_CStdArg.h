/*--------------------------------------------------------------------------------*
  Copyright (C)Nintendo All rights reserved.

  These coded instructions, statements, and computer programs contain proprietary
  information of Nintendo and/or its licensed developers and are protected by
  national and international copyright laws. They may not be disclosed to third
  parties or copied or duplicated in any form, in whole or in part, without the
  prior written consent of Nintendo.

  The content herein is highly confidential and should be handled accordingly.
 *--------------------------------------------------------------------------------*/

#pragma once

/**
* @file
* @brief   \<cstdarg\> 関連のワークアラウンド
*/

#include <nn/cstd/cstd_Config.h>

#if defined(NN_BUILD_CONFIG_COMPILER_VC)
#include <nn/cstd/detail/cstd_CStdArg-compiler.vc.h>
#else
#include <nn/cstd/detail/cstd_CStdArg-compiler.default.h>
#endif


#if defined(NN_BUILD_FOR_DOCUMENT_GENERATION)

/**
* @brief   標準の va_copy と同一です。
*/
#define NN_CSTD_VA_COPY(dst, src)

#endif  /* NN_BUILD_FOR_DOCUMENT_GENERATION */

