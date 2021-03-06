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

#include <nn/nn_Macro.h>

namespace nn {
namespace atk {
namespace detail {
namespace fnd {

//---------------------------------------------------------------------------
//! @internal
//! @brief    パスを操作します。
//!
//! @details  HACK : このクラスは実装途中です。
//!                  必要になった機能を随時実装していきます。
//---------------------------------------------------------------------------
class Path
{
private:
    // インスタンス生成を禁止します。
    Path() NN_NOEXCEPT { }

public:
    // TODO : ConvertToHfioFilePath とかにリネームする
    // TODO : src と dest、引数の順序をかえる
    static void ConvertToPcFilePath(
        const char* src,
        uint32_t srcLength,
        char* dest,
        uint32_t destLength,
        const char* volume,
        uint32_t volumeLength) NN_NOEXCEPT;

    static uint32_t ExpandEnvironmentVariables(
        char* dest,
        uint32_t destLength,
        const char* src,
        uint32_t srcLength) NN_NOEXCEPT;
};

const char* TrimDirPath(const char* path, char delim) NN_NOEXCEPT;

} // namespace nn::atk::detail::fnd
} // namespace nn::atk::detail
} // namespace nn::atk
} // namespace nn
