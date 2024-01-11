object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 600
  ClientWidth  = 1000
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 1083
    Height = 57
    Caption = 'ToolBar1'
    ParentColor = False
    TabOrder = 4
  end
  object Memo1: TMemo
    Left   = 50
    Top    = 250
    Width  = 290
    Height = 242
    Lines.Strings = ('Memo1')
    OEMConvert = True
    TabOrder = 4
  end
  object TreeView1: TTreeView
    Left     = 552
    Top      = 168
    Width    = 392
    Height   = 242
    Indent   = 19
    TabOrder = 4
  end
  object Button1: TButton
    Left     = 950
    Top      = 167
    Width    = 75
    Height   = 25
    Caption  = 'Parse File'
    TabOrder = 4
    OnClick  = Button1Click
  end
  object Button2: TButton
    Left    = 950
    Top     = 136
    Width   = 75
    Height  = 25
    Caption = 'Select File'
    ImageMargins.Left   = 100
    ImageMargins.Top    = 100
    ImageMargins.Right  = 100
    ImageMargins.Bottom = 100
    TabOrder = 6
    OnClick  = Button2Click
  end
  object Edit1: TEdit
    AlignWithMargins = True
    Left     = 550
    Top      = 150
    Width    = 400
    Height   = 25
    TabOrder = 4
    Text     = '/path/to/***.rtz'
  end
  object Button3 : TButton
    Left     = 300
    Top      = 250
    Width    = 75
    Height   = 25
    Caption  = 'Normal'
    TabOrder = 4
    OnClick  = Button3Click
  end
  object Button4 : TButton
    Left     = 300
    Top      = 300
    Width    = 75
    Height   = 25
    Caption  = 'Info'
    TabOrder = 4
    OnClick  = Button4Click
  end
  object Button5 : TButton
    Left     = 300
    Top      = 350
    Width    = 75
    Height   = 25
    Caption  = 'Warn'
    TabOrder = 4
    OnClick  = Button5Click
  end
  object Button6 : TButton
    Left     = 300
    Top      = 400
    Width    = 75
    Height   = 25
    Caption  = 'Danger'
    TabOrder = 4
    OnClick  = Button6Click
  end
  object Button7 : TButton
    Left     = 300
    Top      = 450
    Width    = 75
    Height   = 25
    Caption  = 'Danger'
    TabOrder = 4
    OnClick  = Button7Click
  end
  object OpenDialog1: TOpenDialog
    Left = 900
    Top  = 100
  end
end
