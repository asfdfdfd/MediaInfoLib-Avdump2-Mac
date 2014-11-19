// File_Aes3 - Info Info for AES3 packetized streams
// Copyright (C) 2008-2011 MediaArea.net SARL, Info@MediaArea.net
//
// This library is free software: you can redistribute it and/or modify it
// under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this library. If not, see <http://www.gnu.org/licenses/>.
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// Information about PCM files
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//---------------------------------------------------------------------------
#ifndef MediaInfo_File_Aes3H
#define MediaInfo_File_Aes3H
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include "MediaInfo/File__Analyze.h"
//---------------------------------------------------------------------------

namespace MediaInfoLib
{

//***************************************************************************
// Class File_Aes3
//***************************************************************************

class File_Aes3 : public File__Analyze
{
public :
    //In
    size_t  ByteSize;
    int32u  QuantizationBits;
    bool    From_Raw;
    bool    From_MpegPs;
    bool    From_Aes3;

    //Constructor/Destructor
    File_Aes3();
    ~File_Aes3();

private :
    //Streams management
    void Streams_Fill();

    //Buffer - Global
    void Read_Buffer_Continue ();

    //Buffer - Synchro
    bool Synchronize();
    bool Synched_Test();

    //Buffer - Per element
    void Header_Parse();
    void Data_Parse();

    //Elements
    void Raw();
    void Frame();
    void Frame_WithPadding();
    void Frame_FromMpegPs();

    //Temp
    int64u  Frame_Last_Size;
    int64u  Frame_Last_PTS;
    int8u   number_channels;
    int8u   bits_per_sample;
    int8u   Container_Bits;
    int8u   Stream_Bits;
    int8u   data_type;
    bool    Endianess; //false=BE, true=LE
    bool    IsParsingNonPcm;
    bool    IsPcm;

    //Parser
    File__Analyze* Parser;
    void Parser_Parse(const int8u* Parser_Buffer, size_t Parser_Buffer_Size);
};

} //NameSpace

#endif

