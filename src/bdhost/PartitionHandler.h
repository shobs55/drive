/*
  Copyright (c) 2018 Drive Foundation

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#pragma once

#include "HttpHandler.h"

namespace bdhost
{
  class PartitionHandler : public bdhttp::HttpHandler
  {
  public:

    void ProcessRequest(bdhttp::HttpContext & context) override;

  private:

    void OnFolderRequest(bdhttp::HttpContext & context, const std::string & action);

    void OnPartitionRequest(bdhttp::HttpContext & context, const std::string & name, const std::string & action);

    void OnReadBlock(bdhttp::HttpContext & context, const std::string & name, uint64_t blockCount, uint64_t blockSize);

    void OnWriteBlock(bdhttp::HttpContext & context, const std::string & name, uint64_t blockCount, uint64_t blockSize);

    void OnDelete(bdhttp::HttpContext & context, const std::string & name);

    void OnCreatePartition(bdhttp::HttpContext & context);

    void OnReservePartition(bdhttp::HttpContext & context);

    void OnUnreservePartition(bdhttp::HttpContext & context);
  };
}
