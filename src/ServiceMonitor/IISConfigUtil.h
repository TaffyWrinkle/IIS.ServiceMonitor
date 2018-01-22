// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT license.

#pragma once

#include <Windows.h>
#include <unordered_map>


class IISConfigUtil
{

public:

    IISConfigUtil();
    ~IISConfigUtil();
    HRESULT Initialize();
    HRESULT UpdateEnvironmentVarsToConfig(WCHAR* pstrAppPoolName);
    HRESULT EnableEtwLogging();
    BOOL    IISConsoleLoggingEnabled();

private:
    HRESULT RunCommand(std::wstring * pstrCmd, BOOL fIgnoreError);
    HRESULT BuildAppCmdCommand(std::unordered_map<std::wstring, std::wstring> envSet, WCHAR* pstrAppPoolName, std::wstring** pStrCmd, BOOL fAddCommand);
    BOOL    NameValuePairExist(std::unordered_map<std::wstring, std::wstring> filter, LPTSTR pStrName, LPTSTR pStrValue);
    TCHAR*  m_pstrSysDirPath;
    BOOL    fIISConsoleLoggingEnabled;
};