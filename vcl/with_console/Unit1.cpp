//---------------------------------------------------------------------------

#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>

#include <windows.h>
#include <System.IOUtils.hpp>
#include <direct.h>
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONOUT$", "w", stderr);
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    try {

        AnsiString rtz_path = Edit1->Text;
        int item_count = 0;
        TreeView1->Items->Clear();
        TreeView1->Items->Add(NULL, "route");
        TTreeNode* route_node = TreeView1->Items->Item[item_count++];
        TreeView1->Items->AddChild(route_node, "routeInfo");
        TreeView1->Items->AddChild(route_node, "waypoints");
        TTreeNode* route_info_node = TreeView1->Items->Item[item_count++];
        TTreeNode* waypoints_node = TreeView1->Items->Item[item_count++];

    } catch (...) {

        ShowMessage("Couldn't parse.");
    }

}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    OpenDialog1->Filter = "RTZ File |*xml;*.rtz";
    if(OpenDialog1->Execute())
    {
        Edit1->Text = OpenDialog1->FileName;
    }
    else
    {
        Edit1->Clear();
    }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    print("Normal");
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
    print("Info", GREEN);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
    print("Warn", YELLOW);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
    print("Danger", RED);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
    Memo1->Lines->Clear();
    auto std_out_handle = GetStdHandle((DWORD)-11);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::print(const std::string& str, const enum Color& color) const
{
    Memo1->Lines->Add(str.c_str());
    
    auto std_out_handle = GetStdHandle((DWORD)-11);
    if(color==WHITE)
        SetConsoleTextAttribute(std_out_handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    else if(color==YELLOW)
        SetConsoleTextAttribute(std_out_handle, FOREGROUND_GREEN | FOREGROUND_RED);
    else if(color==GREEN)
        SetConsoleTextAttribute(std_out_handle, FOREGROUND_GREEN);
    else if(color==BLUE)
        SetConsoleTextAttribute(std_out_handle, FOREGROUND_BLUE);
    else if(color==RED)
        SetConsoleTextAttribute(std_out_handle, FOREGROUND_RED);

    std::cout << str << std::endl;

    SetConsoleTextAttribute(std_out_handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

}
