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
* @brief キューのデータに関する API の宣言（NVN8 特殊版）
*/

#pragma once

#include <nn/nn_Common.h>

#include <nn/util/util_BitPack.h>

#include <nn/gfx/gfx_Common.h>
#include <nn/gfx/gfx_Variation-api.nvn.h>

#include <nn/gfx/detail/gfx_Declare.h>
#include <nn/gfx/detail/gfx_Device-api.nvn.8.h>
#include <nn/gfx/detail/gfx_Misc.h>

namespace nn {
namespace gfx {

/**
* @brief キューを表す構造体です（NVN8 特殊版）
*/
template<>
struct QueueImplData< ApiVariationNvn8 >
{
    detail::Ptr< detail::DeviceImpl< ApiVariationNvn8 > > pNnDevice;
    detail::Ptr< void > pNvnQueue;

    NN_ALIGNAS( 8 ) char nvnQueue[ 8192 ]; // Static storage of the NVNqueue object

    enum State
    {
        State_NotInitialized,
        State_Initialized
    };

    enum Flag
    {
        Flag_Shared
    };

    Bit8 state; //!< オブジェクトの状態です
    nn::util::BitPack8 flags; //!< フラグです
    char reserved[ 6 ]; //!< 予約領域です。

    detail::Ptr< void > userPtr; //!< ユーザーポインターです

    detail::Ptr< void > pImpl;
};

}
}
