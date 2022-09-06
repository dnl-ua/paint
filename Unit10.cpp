#include <vcl.h>
#pragma hdrstop

#include "Unit10.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm10 *Form10;
TBitmap *Bitmap;
TRect   copyRect;
int copy_x, copy_y;
bool copy = true;
bool line = false;
bool eraser = false;
int ESize = 5;
int xx, yy;
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
	: TForm(Owner)
{
	// constructor
	Bitmap = new TBitmap();
	Clear1Click(this);
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	// mouse down
	Bitmap->Assign(Image1->Picture);
	Image1->Canvas->MoveTo(X, Y);
	Log->Lines->Add("MoveTo " + IntToStr(X) + " " + IntToStr(Y));
	xx = X; yy = Y;

	if (sbPencil->Down) {
		line = true;
	}
	if (sbEraser->Down) {
		eraser = true;
	}
	if (sbPicker->Down) {
		if (Button == mbLeft) {
			Shape1->Brush->Color = Image1->Canvas->Pixels[X][Y];
			Log->Lines->Add("Brush " + ColorToString(Shape1->Brush->Color));
		}
		if (Button == mbRight) {
			Shape2->Brush->Color = Image1->Canvas->Pixels[X][Y];
			Log->Lines->Add("Brush " + ColorToString(Shape2->Brush->Color));
		}
	}
	if (sbFill->Down) {
		Image1->Canvas->Brush->Color = Shape2->Brush->Color;
		Log->Lines->Add("Brush " + ColorToString(Shape2->Brush->Color));
		Image1->Canvas->FloodFill(X, Y, Image1->Canvas->Pixels[X][Y], fsSurface);
		Log->Lines->Add("FloodFill " + IntToStr(X) + " " + IntToStr(X) + " " + IntToStr(Image1->Canvas->Pixels[X][Y]) + " fsSurface");

	}
	if (sbText->Down) {
		if (FontDialog1->Execute()) {
			Edit1->Font = FontDialog1->Font;
			Edit1->Top = Y+Image1->Top;
			Edit1->Left = X+Image1->Left;
			Edit1->Text = "";
			Edit1->Visible = true;
			Edit1->SetFocus();
		}
	}
	if (sbSelect->Down) {
		copy_x = X;
		copy_y = Y;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	// mouse move
	if (sbPencil->Down && line) {
		Image1->Canvas->Pen->Color = Shape1->Brush->Color;
		Image1->Canvas->Brush->Color = Shape2->Brush->Color;
		Image1->Canvas->LineTo(X, Y);
		Log->Lines->Add("LineTo " + IntToStr(X) + " " + IntToStr(Y));
	}
	if (sbEraser->Down && eraser) {
		Image1->Canvas->Pen->Color = clWhite;
		Log->Lines->Add("Pen  clWhite");
		Image1->Canvas->Brush->Color = clWhite;
		Log->Lines->Add("Brush  clWhite");
		Image1->Canvas->FillRect(Rect(X, Y, X+ESize, Y+ESize));
		Log->Lines->Add("FillRect " + IntToStr(X) + " " + IntToStr(Y) + " " + IntToStr(X+ESize) + " " + IntToStr(Y+ESize));
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	// mouse up
	if (sbLine->Down) {
		Image1->Canvas->LineTo(X, Y);
		Log->Lines->Add("LineTo " + IntToStr(X) + " " + IntToStr(Y));
	}
	if (sbEllipse->Down) {
		Image1->Canvas->Pen->Color = Shape1->Brush->Color;
		Log->Lines->Add("Pen  " + ColorToString(Shape1->Brush->Color));
		Image1->Canvas->Brush->Color = Shape2->Brush->Color;
		Log->Lines->Add("Brush " + ColorToString(Shape2->Brush->Color));
		Image1->Canvas->Ellipse(xx, yy, X, Y);
		Log->Lines->Add("Ellipse " + IntToStr(xx) + " " + IntToStr(yy) + " " + IntToStr(X) + " " + IntToStr(Y));

	}
	if (sbEraser->Down) {
		Image1->Canvas->Pen->Color = Shape1->Brush->Color;
		Log->Lines->Add("Pen  " + ColorToString(Shape1->Brush->Color));
		Image1->Canvas->Brush->Color = Shape2->Brush->Color;
		Log->Lines->Add("Brush " + ColorToString(Shape2->Brush->Color));
	}
	if (sbSelect->Down && copy) {
		Image1->Canvas->DrawFocusRect(Rect(xx, yy, X, Y));
		Log->Lines->Add("DrawFocusRect " + IntToStr(xx) + " " + IntToStr(yy) + " " + IntToStr(X) + " " + IntToStr(Y));
		copyRect.init(xx, yy, X, Y);
		Log->Lines->Add("copyRect.init " + IntToStr(xx) + " " + IntToStr(yy) + " " + IntToStr(X) + " " + IntToStr(Y));
    }
	eraser = false;
	line = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm10::SpinEdit1Change(TObject *Sender)
{
	// size change
	ESize = SpinEdit1->Value;
	Image1->Canvas->Pen->Width = SpinEdit1->Value;
	Log->Lines->Add("Width " + IntToStr(SpinEdit1->Value));
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Shape2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	// brush color
	if (ColorDialog2->Execute()) {
		Shape2->Brush->Color = ColorDialog2->Color;
		Image1->Canvas->Brush->Color = Shape2->Brush->Color;
		Log->Lines->Add("Brush " + ColorToString(Shape2->Brush->Color));
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Shape1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	// pen color
	if (ColorDialog1->Execute()) {
		Shape1->Brush->Color = ColorDialog1->Color;
		Image1->Canvas->Pen->Color = Shape1->Brush->Color;
		Log->Lines->Add("Pen  " + ColorToString(Shape1->Brush->Color));
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Open1Click(TObject *Sender)
{
	// from file
	if (OpenDialog1->Execute()) {
		Image1->Picture->LoadFromFile(OpenDialog1->FileName);
		Log->Lines->Add("Load " + OpenDialog1->FileName);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Save1Click(TObject *Sender)
{
	// to file
	if (SaveDialog1->Execute()) {
		Image1->Picture->SaveToFile(SaveDialog1->FileName);
		Log->Lines->Add("Save " + SaveDialog1->FileName);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Clear1Click(TObject *Sender)
{
	// clear canvas
	Log->Clear();
	Image1->Canvas->Pen->Color = clWhite;
	Image1->Canvas->Brush->Color = clWhite;
	Image1->Canvas->FillRect(Rect(0, 0, Image1->Width, Image1->Height));
	Log->Lines->Add("Pen clWhite");
	Log->Lines->Add("Brush clWhite");
	Log->Lines->Add("FillRect 0 0 " + IntToStr(Image1->Width) + " " + IntToStr(Image1->Height));

	Image1->Canvas->Pen->Color = Shape1->Brush->Color;
	Log->Lines->Add("Pen  " + ColorToString(Shape1->Brush->Color));
	Image1->Canvas->Brush->Color = Shape2->Brush->Color;
	Log->Lines->Add("Brush " + ColorToString(Shape2->Brush->Color));
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Edit1KeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
	// printing text to the canvas
	if (Key == 13) {
		Image1->Canvas->Brush->Style = bsClear;
		Log->Lines->Add("Style bsClear");
		Image1->Canvas->Font = FontDialog1->Font;
		Log->Lines->Add("Font " + FontDialog1->Font->Name);
		Image1->Canvas->TextOutW(xx, yy, Edit1->Text);
		Log->Lines->Add("TextOutW " + IntToStr(xx) + " " + IntToStr(yy) + " " + Edit1->Text);

		Edit1->Visible = false;
		Image1->Canvas->Brush->Style = bsSolid;
		Log->Lines->Add("Style bsSolid");
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Undo1Click(TObject *Sender)
{
	// ctrl-z
	Image1->Canvas->Draw(0, 0, Bitmap);
}
//---------------------------------------------------------------------------
void __fastcall TForm10::FormResize(TObject *Sender)
{
	// changing bitmap dimensions on window resize
	Bitmap->Width = Image1->Width;
	Bitmap->Height = Image1->Height;
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Paste1Click(TObject *Sender)
{
	if (!copy) {
		Image1->Canvas->CopyRect(Rect(0, 0, copyRect.Size.Width, copyRect.Size.Height),
								 Image1->Canvas, copyRect);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Copy1Click(TObject *Sender)
{
	copy = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Openvector1Click(TObject *Sender)
{
	if (OpenDialog2->Execute()) {
		Clear1Click(Sender);
		Log->Lines->LoadFromFile(OpenDialog2->FileName);
		for (int i = 0; i < Log->Lines->Count; i++) {
			AnsiString s = Log->Lines->Strings[i];
			AnsiString s1 = s.SubString(1, s.Pos(' ')-1);
			s.Delete(1, s.Pos(' '));
			if (s1 == "MoveTo") {
				int x = StrToInt(s.SubString(1, s.Pos(' ')-1));
				s.Delete(1, s.Pos(' '));
				int y = StrToInt(s);
				Image1->Canvas->MoveTo(x, y);
			}
			if (s1 == "LineTo") {
				int x = StrToInt(s.SubString(1, s.Pos(' ')-1));
				s.Delete(1, s.Pos(' '));
				int y = StrToInt(s);
				Image1->Canvas->LineTo(x, y);
			}
			if (s1 == "Pen") {
				AnsiString pen = s.SubString(1, s.Length());
				pen = StringReplace(pen, " ", "", TReplaceFlags() << rfReplaceAll);
				Image1->Canvas->Pen->Color = StringToColor(pen);
			}
			if (s1 == "Brush") {
				AnsiString brush = s.SubString(1, s.Length());
				brush = StringReplace(brush, " ", "", TReplaceFlags() << rfReplaceAll);
				Image1->Canvas->Brush->Color = StringToColor(brush);
			}
			if (s1 == "FillRect") {
				int w = StrToInt(s.SubString(1, s.Pos(' ')-1));
				s.Delete(1, s.Pos(' '));
				int x = StrToInt(s.SubString(1, s.Pos(' ')-1));
				s.Delete(1, s.Pos(' '));
				int y = StrToInt(s.SubString(1, s.Pos(' ')-1));
				s.Delete(1, s.Pos(' '));
				int z = StrToInt(s);
				Image1->Canvas->FillRect(Rect(w, x, y, z));
			}
			if (s1 == "Ellipse") {
				int w = StrToInt(s.SubString(1, s.Pos(' ')-1));
				s.Delete(1, s.Pos(' '));
				int x = StrToInt(s.SubString(1, s.Pos(' ')-1));
				s.Delete(1, s.Pos(' '));
				int y = StrToInt(s.SubString(1, s.Pos(' ')-1));
				s.Delete(1, s.Pos(' '));
				int z = StrToInt(s);
				Image1->Canvas->Ellipse(w, x, y, z);
			}
			if (s1 == "Style") {
				AnsiString style = s.SubString(1, s.Length());
				style = StringReplace(style, " ", "", TReplaceFlags() << rfReplaceAll);
				//Image1->Canvas->Brush->Style = style;
			}
			if (s1 == "Font") {
				AnsiString font = s.SubString(1, s.Length());
				font = StringReplace(font, " ", "", TReplaceFlags() << rfReplaceAll);
				Image1->Canvas->Font->Name = font;
			}
			if (s1 == "TextOutW") {
				AnsiString font = s.SubString(1, s.Length());
				int x = StrToInt(s.SubString(1, s.Pos(' ')-1));
				s.Delete(1, s.Pos(' '));
				int y = StrToInt(s.SubString(1, s.Pos(' ')-1));
				s.Delete(1, s.Pos(' '));
				AnsiString z = s;
                Image1->Canvas->TextOutW(x, y, z);
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Savevector1Click(TObject *Sender)
{
	if (SaveDialog2->Execute()) {
		Log->Lines->SaveToFile(SaveDialog2->FileName);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm10::CheckBox1Click(TObject *Sender)
{
	Log->Visible = CheckBox1->Checked;
}
//---------------------------------------------------------------------------

