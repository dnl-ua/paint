//---------------------------------------------------------------------------

#ifndef Unit10H
#define Unit10H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Samples.Spin.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm10 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TGroupBox *GroupBox1;
	TSpeedButton *sbPencil;
	TSpeedButton *SpeedButton2;
	TSpeedButton *sbEllipse;
	TSpeedButton *sbEraser;
	TSpeedButton *sbPicker;
	TShape *Shape1;
	TSpinEdit *SpinEdit1;
	TSpeedButton *sbLine;
	TShape *Shape2;
	TColorDialog *ColorDialog1;
	TColorDialog *ColorDialog2;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Open1;
	TMenuItem *Save1;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TSpeedButton *sbFill;
	TSpeedButton *sbText;
	TMenuItem *Canvas1;
	TMenuItem *Clear1;
	TEdit *Edit1;
	TFontDialog *FontDialog1;
	TMenuItem *Undo1;
	TSpeedButton *sbSelect;
	TMenuItem *Selection1;
	TMenuItem *Copy1;
	TMenuItem *Paste1;
	TMemo *Log;
	TMenuItem *Openvector1;
	TMenuItem *Savevector1;
	TOpenDialog *OpenDialog2;
	TSaveDialog *SaveDialog2;
	TCheckBox *CheckBox1;
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall SpinEdit1Change(TObject *Sender);
	void __fastcall Shape2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall Shape1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall Open1Click(TObject *Sender);
	void __fastcall Save1Click(TObject *Sender);
	void __fastcall Clear1Click(TObject *Sender);
	void __fastcall Edit1KeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Undo1Click(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall Paste1Click(TObject *Sender);
	void __fastcall Copy1Click(TObject *Sender);
	void __fastcall Openvector1Click(TObject *Sender);
	void __fastcall Savevector1Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm10(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm10 *Form10;
//---------------------------------------------------------------------------
#endif
