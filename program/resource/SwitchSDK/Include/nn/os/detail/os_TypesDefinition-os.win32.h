/*--------------------------------------------------------------------------------*
  Copyright (C)Nintendo All rights reserved.

  These coded instructions, statements, and computer programs contain proprietary
  information of Nintendo and/or its licensed developers and are protected by
  national and international copyright laws. They may not be disclosed to third
  parties or copied or duplicated in any form, in whole or in part, without the
  prior written consent of Nintendo.

  The content herein is highly confidential and should be handled accordingly.
 *--------------------------------------------------------------------------------*/

/*
 * このファイルを編集しないでください。
 * このファイルは自動生成されたファイルを元に作成されたものです。
 */

// NOLINT(build/header_guard)

#define NN_OS_SELECT_TYPES_DEFINITION         0x1  // NOLINT(readability/define)

#if 1
//  InternalConditionVariable の Win32 実装において、
//  std::condition_variable_any を利用する場合はこちらを適用。
#define NN_OS_SIZEOF_THREAD_TYPE              0x120// NOLINT(readability/define)
#define NN_OS_SIZEOF_SEMAPHORE_TYPE           0x34 // NOLINT(readability/define)
#define NN_OS_SIZEOF_MESSAGE_QUEUE_TYPE       0x4c // NOLINT(readability/define)
#define NN_OS_SIZEOF_EVENT_TYPE               0x34 // NOLINT(readability/define)
#define NN_OS_SIZEOF_TIMER_EVENT_TYPE         0x50 // NOLINT(readability/define)
#define NN_OS_SIZEOF_INTERRUPT_EVENT_TYPE     0x14 // NOLINT(readability/define)
#define NN_OS_SIZEOF_SYSTEM_EVENT_TYPE        0x38 // NOLINT(readability/define)
#define NN_OS_SIZEOF_MULTI_WAIT_TYPE          0x40 // NOLINT(readability/define)
#define NN_OS_SIZEOF_MULTI_WAIT_HOLDER_TYPE   0x20 // NOLINT(readability/define)
#define NN_OS_SIZEOF_MUTEX_TYPE               0x28 // NOLINT(readability/define)
#define NN_OS_SIZEOF_CONDITION_VARIABLE_TYPE  0x0c // NOLINT(readability/define)
#define NN_OS_SIZEOF_BARRIER_TYPE             0x2c // NOLINT(readability/define)
#define NN_OS_SIZEOF_TLS_SLOT                 0x04 // NOLINT(readability/define)
#else
//  InternalConditionVariable の Win32 実装において、
//  ::CONDITION_VARIABLE 型を利用する場合はこちらを適用。
#define NN_OS_SIZEOF_THREAD_TYPE              0x110// NOLINT(readability/define)
#define NN_OS_SIZEOF_SEMAPHORE_TYPE           0x30 // NOLINT(readability/define)
#define NN_OS_SIZEOF_MESSAGE_QUEUE_TYPE       0x44 // NOLINT(readability/define)
#define NN_OS_SIZEOF_EVENT_TYPE               0x30 // NOLINT(readability/define)
#define NN_OS_SIZEOF_TIMER_EVENT_TYPE         0x50 // NOLINT(readability/define)
#define NN_OS_SIZEOF_INTERRUPT_EVENT_TYPE     0x14 // NOLINT(readability/define)
#define NN_OS_SIZEOF_SYSTEM_EVENT_TYPE        0x34 // NOLINT(readability/define)
#define NN_OS_SIZEOF_MULTI_WAIT_TYPE          0x40 // NOLINT(readability/define)
#define NN_OS_SIZEOF_MULTI_WAIT_HOLDER_TYPE   0x20 // NOLINT(readability/define)
#define NN_OS_SIZEOF_MUTEX_TYPE               0x28 // NOLINT(readability/define)
#define NN_OS_SIZEOF_CONDITION_VARIABLE_TYPE  0x08 // NOLINT(readability/define)
#define NN_OS_SIZEOF_BARRIER_TYPE             0x28 // NOLINT(readability/define)
#define NN_OS_SIZEOF_TLS_SLOT                 0x04 // NOLINT(readability/define)
#endif
