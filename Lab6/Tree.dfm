object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 423
  ClientWidth = 690
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 120
  TextHeight = 16
  object InsertKeyLabel: TLabel
    Left = 352
    Top = 26
    Width = 20
    Height = 16
    Caption = 'Key'
  end
  object InsertValLabel: TLabel
    Left = 448
    Top = 26
    Width = 26
    Height = 16
    Caption = 'Data'
  end
  object FindLabel: TLabel
    Left = 360
    Top = 168
    Width = 101
    Height = 24
    Caption = 'Find by key'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object DeleteLabel: TLabel
    Left = 536
    Top = 168
    Width = 123
    Height = 24
    Caption = 'Delete by key'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 456
    Top = 304
    Width = 99
    Height = 19
    Caption = 'Find close key'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object TreeView1: TTreeView
    Left = 40
    Top = 26
    Width = 257
    Height = 223
    Indent = 19
    TabOrder = 0
  end
  object InputField: TEdit
    Left = 336
    Top = 48
    Width = 65
    Height = 24
    NumbersOnly = True
    TabOrder = 1
  end
  object InsertButton: TButton
    Left = 336
    Top = 87
    Width = 153
    Height = 49
    Caption = 'Insert'
    TabOrder = 2
    OnClick = InsertButtonClick
  end
  object BalanceButton: TButton
    Left = 552
    Top = 32
    Width = 105
    Height = 104
    Caption = 'Balance'
    TabOrder = 3
    OnClick = BalanceButtonClick
  end
  object ValBox: TEdit
    Left = 424
    Top = 48
    Width = 65
    Height = 24
    TabOrder = 4
  end
  object Memo1: TMemo
    Left = 40
    Top = 272
    Width = 257
    Height = 73
    ScrollBars = ssVertical
    TabOrder = 5
  end
  object Path1Button: TButton
    Left = 40
    Top = 368
    Width = 75
    Height = 33
    Caption = #1055#1088#1103#1084#1086#1081
    TabOrder = 6
    OnClick = Path1ButtonClick
  end
  object Path2Butotn: TButton
    Left = 129
    Top = 368
    Width = 75
    Height = 33
    Caption = #1054#1073#1088#1072#1090#1085#1099#1081
    TabOrder = 7
    OnClick = Path2ButotnClick
  end
  object Path3Button: TButton
    Left = 222
    Top = 368
    Width = 75
    Height = 33
    Caption = #1055#1086' '#1074#1086#1079#1088'.'
    TabOrder = 8
    OnClick = Path3ButtonClick
  end
  object FindByKeyBox: TEdit
    Left = 352
    Top = 208
    Width = 121
    Height = 24
    NumbersOnly = True
    TabOrder = 9
  end
  object FindByKeyButton: TButton
    Left = 352
    Top = 248
    Width = 121
    Height = 25
    Caption = 'Find!'
    TabOrder = 10
    OnClick = FindByKeyButtonClick
  end
  object DeleteByKeyBox: TEdit
    Left = 536
    Top = 208
    Width = 121
    Height = 24
    NumbersOnly = True
    TabOrder = 11
  end
  object DeleteByKeyButton: TButton
    Left = 536
    Top = 248
    Width = 121
    Height = 25
    Caption = 'Delete!'
    TabOrder = 12
    OnClick = DeleteByKeyButtonClick
  end
  object FindNearBox: TEdit
    Left = 448
    Top = 329
    Width = 121
    Height = 24
    NumbersOnly = True
    TabOrder = 13
  end
  object FindNearButton: TButton
    Left = 472
    Top = 359
    Width = 75
    Height = 25
    Caption = 'Find!'
    TabOrder = 14
    OnClick = FindNearButtonClick
  end
end
