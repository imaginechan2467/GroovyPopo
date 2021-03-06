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
 * @brief       オーディオ入力に関する型や定数を定義します。
 */

#include <nn/os/os_MemoryHeapCommon.h>
#include <nn/os/os_Mutex.h>
#include <nn/audio/audio_SampleFormat.h>
#include <nn/audio/audio_AudioInOutCommonTypes.h>
#include <nn/os/os_SystemEvent.h>
namespace nn {
namespace audio {

/**
 * @brief       オーディオ入力の状態を表す列挙型です。
 */
enum AudioInState
{
    AudioInState_Started,               //!< 動作しています
    AudioInState_Stopped,               //!< 停止しています
};

/**
 * @brief       オーディオ入力用のパラメータです。
 */
struct AudioInParameter
{
    int32_t sampleRate;                 //!< サンプルレート（0 指定時はデフォルト値）
    uint16_t _channelCount;
    uint16_t _reserved;
};

/**
 * @brief       オーディオ入力バッファを表す構造体です。
 *
 * @details
 * メンバー変数を直接変更することは禁止です。 @n
 * 次の関数を介して、本構造体を利用してください。
 *
 * - @ref SetAudioInBufferInfo()
 * - @ref GetAudioInBufferDataPointer()
 * - @ref GetAudioInBufferDataSize()
 * - @ref AppendAudioInBuffer()
 * - @ref GetReleasedAudioInBuffer()
 * - @ref ContainsAudioInBuffer()
 *
 * 上記の関数を利用するには nn/audio.h をインクルードする必要があります。
 */
struct AudioInBuffer
{
    static const size_t AddressAlignment = nn::os::MemoryPageSize; //!< AudioInBuffer に要求されるアライメント
    static const size_t SizeGranularity = nn::os::MemoryPageSize;  //!< AudioInBuffer に要求されるサイズの粒度

    union
    {
        AudioInBuffer* pNext;
        uint64_t _pNextU64;
    };
    union
    {
        void* buffer;
        uint64_t _bufferU64;
    };
    union
    {
        size_t bufferSize;
        uint64_t _bufferSizeU64;
    };
    union
    {
        size_t size;
        uint64_t _sizeU64;
    };
    union
    {
       size_t offset;
       uint64_t _offsetU64;
    };
};

/**
 * @brief   オーディオ入力バッファのアライメントを指定するマクロです。
 */
#define NN_AUDIO_ALIGNAS_AUDIO_IN_BUFFER_ALIGN NN_ALIGNAS(4096)

/**
 * @brief       オーディオ入力を管理するための構造体です。
 *
 * @details
 * メンバー変数を直接変更することは禁止です。 @n
 * 次の関数を介して、本構造体を利用してください。
 *
 * - @ref OpenDefaultAudioIn(AudioIn *pOutAudioIn, const AudioInParameter &parameter)
 * @cond
 * - @ref OpenDefaultAudioIn(AudioIn *pOutAudioIn, nn::os::SystemEvent *pOutSystemEvent, const AudioInParameter &parameter)
 * @endcond
 * - @ref OpenAudioIn(AudioIn *pOutAudioIn, const char *name, const AudioInParameter &parameter)
 * @cond
 * - @ref OpenAudioIn(AudioIn *pOutAudioIn, nn::os::SystemEvent *pOutSystemEvent, const char *name, const AudioInParameter &parameter)
 * @endcond
 * - @ref CloseAudioIn()
 * - @ref StartAudioIn()
 * - @ref StopAudioIn()
 * - @ref GetAudioInState()
 * - @ref GetAudioInName()
 * - @ref GetAudioInSampleRate()
 * - @ref GetAudioInChannelCount()
 * - @ref GetAudioInSampleFormat()
 * - @ref AppendAudioInBuffer()
 * - @ref GetReleasedAudioInBuffer()
 * - @ref ContainsAudioInBuffer()
 *
 * 上記の関数を利用するには nn/audio.h をインクルードする必要があります。
 */
struct AudioIn
{
    int32_t sampleRate;
    int32_t channelCount;
    SampleFormat sampleFormat;
    AudioInState state;

    static const int NameLength = 256;
    char name[NameLength];

    bool isMutexInitialized;
    mutable os::MutexType mutex;
    AudioInBufferList appendList;
    AudioInBufferList releaseList;

    int32_t internalBufferSampleCount;
    void* pDevice;
#if defined(NN_BUILD_CONFIG_OS_WIN)
    void* pAudioClient;
    void* pAudioCaptureClient;
    void* hEvent;
#endif

    int8_t _reserved[8];
};

/**
 * @brief       サポートするオーディオ入力の最大同時接続数です。
 */
const int AudioInCountMax = 4;

/**
 * @brief        オーディオ入力に追加できる AudioInBuffer の上限数です。
 */
const int AudioInBufferCountMax = 32;

/**
 * @brief       オーディオ入力情報を表す構造体です。
 *
 * @details
 * メンバー変数を直接変更することは禁止です。 @n
 * 次の関数を介して、本構造体を利用してください。
 *
 * - @ref ListAudioIns()
 *
 * 上記の関数を利用するには nn/audio.h をインクルードする必要があります。
 */
struct AudioInInfo
{
    char name[AudioIn::NameLength];     //!< UTF-8 で表現された、オーディオ出力の名前です。
};

}  // namespace audio
}  // namespace nn
