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
 * @brief   条件変数に関する Horizon 依存のマクロの定義
 */

#pragma once

//--------------------------------------------------------------------------
// 静的に初期化された ConditionVariableType オブジェクトを Horizon 用に配置します。
//
#define NN_OS_CONDITION_VARIABLE_INITIALIZER()                      \
        {                                                           \
            ::nn::os::ConditionVariableType::State_Initialized,     \
            { { 0 }, },                                             \
        }

//--------------------------------------------------------------------------

