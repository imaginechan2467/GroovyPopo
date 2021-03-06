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

namespace nn {
namespace atk {
namespace detail {

struct Command
{
    struct Command* next;
    uint32_t id;
    uint32_t tag;
    uintptr_t memory_next;
};

} // namespace nn::atk::detail
} // namespace nn::atk
} // namespace nn
