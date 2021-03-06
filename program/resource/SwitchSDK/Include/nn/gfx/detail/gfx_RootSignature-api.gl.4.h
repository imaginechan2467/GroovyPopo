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

#include <nn/gfx/gfx_Variation-api.gl.h>

#include <nn/gfx/detail/gfx_RootSignature-api.common.h>

namespace nn {
namespace gfx {
namespace detail {

template<>
class RootSignatureImpl< ApiVariationGl4 >
    : public RootSignatureImplCommon< ApiVariationGl4 >
{};

}
}
}
