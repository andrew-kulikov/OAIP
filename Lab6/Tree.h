#ifndef TreeH
#define TreeH

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include "BinaryTree.h"
#include <Vcl.Grids.hpp>

class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TTreeView *TreeView1;
    TEdit *InputField;
    TButton *InsertButton;
    TButton *BalanceButton;
    TEdit *ValBox;
    TLabel *InsertKeyLabel;
    TLabel *InsertValLabel;
    TMemo *Memo1;
    TButton *Path1Button;
    TButton *Path2Butotn;
    TButton *Path3Button;
    TLabel *FindLabel;
    TEdit *FindByKeyBox;
    TButton *FindByKeyButton;
    TLabel *DeleteLabel;
    TEdit *DeleteByKeyBox;
    TButton *DeleteByKeyButton;
    TLabel *Label1;
    TEdit *FindNearBox;
    TButton *FindNearButton;
    void __fastcall InsertButtonClick(TObject *Sender);
    void __fastcall BalanceButtonClick(TObject *Sender);
    void __fastcall Path1ButtonClick(TObject *Sender);
    void __fastcall Path2ButotnClick(TObject *Sender);
    void __fastcall Path3ButtonClick(TObject *Sender);
    void __fastcall FindByKeyButtonClick(TObject *Sender);
    void __fastcall DeleteByKeyButtonClick(TObject *Sender);
    void __fastcall FindNearButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};

extern PACKAGE TForm1 *Form1;

#endif
