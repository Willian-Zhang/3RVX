#pragma once

#include "afxwin.h"
#include "KeyReceiver.h"

class HotkeyPrompt : public CDialog {

	DECLARE_DYNAMIC(HotkeyPrompt)

public:
	HotkeyPrompt(CWnd* pParent = NULL);   // standard constructor
	virtual ~HotkeyPrompt();
    virtual BOOL OnClose();

	enum { IDD = IDD_HOTKEYPROMPT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

private:
    HHOOK _keyHook;
    HHOOK _mouseHook;
    void Hook();

private:
    CStatic _keys;
    CButton _save;
};
