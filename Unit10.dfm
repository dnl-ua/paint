object Form10: TForm10
  Left = 549
  Top = 300
  Caption = 'Form10'
  ClientHeight = 765
  ClientWidth = 1136
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesigned
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 65
    Width = 1136
    Height = 700
    Align = alClient
    OnMouseDown = Image1MouseDown
    OnMouseMove = Image1MouseMove
    OnMouseUp = Image1MouseUp
    ExplicitTop = 71
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 1136
    Height = 65
    Align = alTop
    TabOrder = 0
    object sbPencil: TSpeedButton
      Left = 11
      Top = 15
      Width = 34
      Height = 34
      GroupIndex = 1
      Down = True
      Caption = 'S'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'UD Digi Kyokasho NK-B'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
    end
    object SpeedButton2: TSpeedButton
      Left = -121
      Top = 423
      Width = 30
      Height = 31
      GroupIndex = 1
    end
    object sbEllipse: TSpeedButton
      Left = 91
      Top = 15
      Width = 34
      Height = 34
      GroupIndex = 1
      Caption = 'O'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Segoe UI'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object sbEraser: TSpeedButton
      Left = 131
      Top = 15
      Width = 34
      Height = 34
      GroupIndex = 1
      Caption = 'E'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object sbPicker: TSpeedButton
      Left = 171
      Top = 15
      Width = 34
      Height = 34
      GroupIndex = 1
      Caption = 'P'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Shape1: TShape
      Left = 419
      Top = 15
      Width = 34
      Height = 34
      Brush.Color = clBackground
      OnMouseUp = Shape1MouseUp
    end
    object sbLine: TSpeedButton
      Left = 51
      Top = 15
      Width = 34
      Height = 34
      GroupIndex = 1
      Caption = '|'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Shape2: TShape
      Left = 459
      Top = 15
      Width = 34
      Height = 34
      OnMouseUp = Shape2MouseUp
    end
    object sbFill: TSpeedButton
      Left = 251
      Top = 15
      Width = 34
      Height = 34
      GroupIndex = 1
      Caption = 'F'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object sbText: TSpeedButton
      Left = 211
      Top = 15
      Width = 34
      Height = 34
      GroupIndex = 1
      Caption = 'T'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object sbSelect: TSpeedButton
      Left = 291
      Top = 15
      Width = 34
      Height = 34
      GroupIndex = 1
      Caption = '[   ]'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object SpinEdit1: TSpinEdit
    Left = 339
    Top = 15
    Width = 42
    Height = 29
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    MaxValue = 10
    MinValue = 1
    ParentFont = False
    TabOrder = 1
    Value = 1
    OnChange = SpinEdit1Change
  end
  object Edit1: TEdit
    Left = 8
    Top = 362
    Width = 89
    Height = 21
    TabOrder = 2
    TextHint = 'Text'
    Visible = False
    OnKeyUp = Edit1KeyUp
  end
  object Log: TMemo
    Left = 840
    Top = 96
    Width = 209
    Height = 537
    Lines.Strings = (
      'Log')
    TabOrder = 3
    Visible = False
  end
  object CheckBox1: TCheckBox
    Left = 512
    Top = 32
    Width = 97
    Height = 17
    Caption = 'Log'
    TabOrder = 4
    OnClick = CheckBox1Click
  end
  object ColorDialog1: TColorDialog
    Left = 24
    Top = 216
  end
  object ColorDialog2: TColorDialog
    Left = 24
    Top = 264
  end
  object MainMenu1: TMainMenu
    Left = 24
    Top = 72
    object File1: TMenuItem
      Caption = 'File'
      object Open1: TMenuItem
        Caption = 'Open'
        OnClick = Open1Click
      end
      object Save1: TMenuItem
        Caption = 'Save'
        OnClick = Save1Click
      end
      object Openvector1: TMenuItem
        Caption = 'Open vector'
        OnClick = Openvector1Click
      end
      object Savevector1: TMenuItem
        Caption = 'Save vector'
        OnClick = Savevector1Click
      end
    end
    object Canvas1: TMenuItem
      Caption = 'Edit'
      object Undo1: TMenuItem
        Caption = 'Undo'
        ShortCut = 16474
        OnClick = Undo1Click
      end
      object Clear1: TMenuItem
        Caption = 'Clear'
        OnClick = Clear1Click
      end
    end
    object Selection1: TMenuItem
      Caption = 'Selection'
      object Copy1: TMenuItem
        Caption = 'Copy'
        ShortCut = 16451
        OnClick = Copy1Click
      end
      object Paste1: TMenuItem
        Caption = 'Paste'
        ShortCut = 16470
        OnClick = Paste1Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 24
    Top = 120
  end
  object SaveDialog1: TSaveDialog
    Left = 24
    Top = 168
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Left = 24
    Top = 312
  end
  object OpenDialog2: TOpenDialog
    Left = 96
    Top = 120
  end
  object SaveDialog2: TSaveDialog
    Left = 96
    Top = 168
  end
end
