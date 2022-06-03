#include "Minesweeper.h"

wxIMPLEMENT_APP(Minesweeper);

Minesweeper::Minesweeper() {

}

Minesweeper::~Minesweeper() {

}

bool Minesweeper::OnInit() {
	m_frame1 = new mMain();
	m_frame1->Show();

	return true;
}