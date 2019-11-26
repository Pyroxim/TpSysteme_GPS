object Form1: TForm1
  Left = 240
  Top = 0
  Caption = 'Form1'
  ClientHeight = 300
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 195
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Ouvrir port'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 290
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Fermer port'
    Enabled = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 242
    Top = 39
    Width = 75
    Height = 25
    Caption = 'Lire donn'#233'es'
    Enabled = False
    TabOrder = 2
    OnClick = Button3Click
  end
  object MemoGlobal: TMemo
    Left = 16
    Top = 80
    Width = 209
    Height = 201
    TabOrder = 3
    Visible = False
  end
  object MemoLat: TMemo
    Left = 256
    Top = 80
    Width = 161
    Height = 89
    TabOrder = 4
  end
  object MemoLong: TMemo
    Left = 442
    Top = 80
    Width = 161
    Height = 89
    TabOrder = 5
  end
  object MemoProf: TMemo
    Left = 256
    Top = 192
    Width = 161
    Height = 89
    TabOrder = 6
  end
  object MemoTemp: TMemo
    Left = 442
    Top = 192
    Width = 161
    Height = 89
    TabOrder = 7
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 608
  end
end
