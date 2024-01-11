//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
#include <System.Classes.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
#include <string>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.Samples.Gauges.hpp>
#include <Vcl.FileCtrl.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Outline.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:
    TToolBar *ToolBar1;
    TMemo *Memo1;
    TTreeView *TreeView1;
    TEdit *Edit1;
    TButton *Button1;
    TButton *Button3;
    TButton *Button4;
    TButton *Button5;
    TButton *Button6;
    TOpenDialog *OpenDialog1;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button5Click(TObject *Sender);
    void __fastcall Button6Click(TObject *Sender);
    void __fastcall Button7Click(TObject *Sender);
private:
    enum Color {WHITE, YELLOW, GREEN, BLUE, RED};
    __fastcall void print(const std::string& str, const enum Color& color=WHITE) const;
public:    
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
