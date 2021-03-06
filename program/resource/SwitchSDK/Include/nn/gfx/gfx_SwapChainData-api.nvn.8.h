/*--------------------------------------------------------------------------------*
  Copyright (C)Nintendo All rights reserved.

  These coded instructions, statements, and computer programs contain proprietary
  information of Nintendo and/or its licensed developers and are protected by
  national and international copyright laws. They may not be disclosed to third
  parties or copied or duplicated in any form, in whole or in part, without the
  prior written consent of Nintendo.

  The content herein is highly confidential and should be handled accordingly.
 *--------------------------------------------------------------------------------*/

/**
* @file
* @brief スワップチェーンのデータに関する API の宣言（NVN8 特殊版）
*/

#pragma once

#include <nn/nn_Common.h>

#include <nn/util/util_BitPack.h>

#include <nn/gfx/gfx_Common.h>
#include <nn/gfx/gfx_Variation-api.nvn.h>
#include <nn/gfx/gfx_TextureData-api.nvn.8.h>

#include <nn/gfx/detail/gfx_Declare.h>
#include <nn/gfx/detail/gfx_Misc.h>

namespace nn {
namespace gfx {

/**
* @brief スワップチェーンを表す構造体です（NVN8 特殊版）
*/
template<>
struct SwapChainImplData< ApiVariationNvn8 >
{
    enum State
    {
        State_NotInitialized,
        State_Initialized
    };

    enum Flag
    {
        Flag_IsFirstPresentation,
        Flag_Acquired
    };

    static const int NvnMaxScanBufferCount = 4;

    detail::Ptr< const detail::DeviceImpl< ApiVariationNvn8 > > pNnDevice; //!< デバイスへのポインターです
    detail::Ptr< void > pNvnWindow;

    char nvnWindow[ 384 ]; // Data storage for the underlying NVNwindow

    Bit8 state; //!< オブジェクトの状態です。
    nn::util::BitPack8 flag; //!< フラグです
    char reserved[ 2 ]; //!< 予約領域です。
    uint32_t currentScanBufferIndex;
    uint32_t totalScanBuffers;
    char reserved2[ 4 ]; //!< 予約領域です。

    TextureImplData< ApiVariationNvn8 > scanBufferTextures[ NvnMaxScanBufferCount ]; // スキャンバッファーです
    ColorTargetViewImplData< ApiVariationNvn8 > scanBufferViews[ NvnMaxScanBufferCount ]; //!< スキャンバッファービューです

    detail::Ptr< void > userPtr; //!< ユーザーポインターです
};

}
}
