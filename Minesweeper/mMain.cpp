#include "mMain.h"

wxBEGIN_EVENT_TABLE(mMain, wxFrame)
wxEND_EVENT_TABLE()

mMain::mMain() : wxFrame(nullptr, wxID_ANY, "Minesweeper", wxPoint(30, 30), wxSize(800, 600)){
	
	btn = new wxButton* [mWidth * mHeight];
	wxGridSizer* grid = new wxGridSizer(mWidth, mHeight, 0, 0);

	mField = new int[mWidth * mHeight];

	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	for (int x = 0; x < mWidth; x++) {
		for (int y = 0; y < mHeight; y++) {
			btn[y * mWidth + x] = new wxButton(this, 10000 + (y * mWidth + x));
			btn[y * mWidth + x]->SetFont(font);
			grid->Add(btn[y * mWidth + x], 1, wxEXPAND | wxALL);

			btn[y * mWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &mMain::OnButtonClicked, this);
			mField[y * mWidth + x] = 0;
		}
	}

	this->SetSizer(grid);
	grid->Layout();

}

mMain::~mMain() {
	delete[]btn;
}

void mMain::OnButtonClicked(wxCommandEvent& evt) {
	int x = (evt.GetId() - 10000) % mWidth;
	int y = (evt.GetId() - 10000) / mWidth;

	if (bFirstClick) {
		int mines = 30;

		while (mines) {
			int rx = rand() % mWidth;
			int ry = rand() % mHeight;

			if (mField[ry * mWidth + rx] == 0 && rx != x && ry != y) {
				mField[ry * mWidth + rx] = -1;
				mines--;
			}
		}
		bFirstClick = false;
	}

	btn[y * mWidth + x]->Enable(false);

	if (mField[y * mWidth + x] == -1) {
		wxMessageBox("BOOOOOOOOOM!!! - GAME OVER :(");

		bFirstClick = true;
		for (int x = 0; x < mWidth; x++) {
			for(int y = 0; y < mHeight; y++) {
				mField[y * mWidth + x] = 0;
				btn[y * mWidth + x]->SetLabel("");
				btn[y * mWidth + x]->Enable(true);
			}
		}
	}
	else {
		int mine_count = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (x + i >= 0 && x + i < mWidth && y + j >= 0 && y + j < mHeight) {
					if (mField[(y + j) * mWidth + (x + i)] == -1)
						mine_count++;
				}
			}
		}
		if (mine_count > 0) {
			btn[y * mWidth + x]->SetLabel(std::to_string(mine_count));
		}
	}

	evt.Skip();
}