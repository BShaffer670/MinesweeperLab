#pragma once

#include"wx/wx.h"
#include "mMain.h"

class Minesweeper : public wxApp{
public:
	Minesweeper();
	~Minesweeper();
private:
	mMain* m_frame1 = nullptr;
public:
	virtual bool OnInit();

};

