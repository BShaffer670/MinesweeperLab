#pragma once
#include"wx/wx.h"

class mMain : public wxFrame
{
public:
	mMain();
	~mMain();

public:
	int mWidth = 10;
	int mHeight = 10;
	wxButton** btn;
	int* mField = nullptr;
	bool bFirstClick = true;

	void OnButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

