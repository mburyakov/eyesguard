object BreakWnd: TBreakWnd
  Left = 475
  Top = 194
  BorderStyle = bsNone
  Caption = 'BreakWnd'
  ClientHeight = 291
  ClientWidth = 473
  Color = clBlack
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Visible = True
  WindowState = wsMaximized
  OnClose = FormClose
  OnMouseMove = FormMouseMove
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object BreakLabel1: TLabel
    Left = 0
    Top = 0
    Width = 473
    Height = 136
    Align = alTop
    Alignment = taCenter
    AutoSize = False
    Caption = #1055#1045#1056#1045#1056#1067#1042'!!!'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clLime
    Font.Height = -25
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
    Layout = tlBottom
    OnMouseMove = FormMouseMove
  end
  object BreakLabel2: TLabel
    Left = 0
    Top = 136
    Width = 473
    Height = 145
    Align = alTop
    Alignment = taCenter
    AutoSize = False
    Caption = #1044#1072#1081' '#1089#1074#1086#1080#1084' '#1075#1083#1072#1079#1072#1084' '#1086#1090#1076#1086#1093#1085#1091#1090#1100'!'
    Color = clBtnFace
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clYellow
    Font.Height = -19
    Font.Name = 'Arial'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    Transparent = True
    Layout = tlCenter
    OnMouseMove = FormMouseMove
  end
end
