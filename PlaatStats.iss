;
; PlaatStats windows installer configurationm file.
;
; The file can be processed with "Inno Setup Compiler v5.3.8"
;
; All Copyrights Reserved (c) PlaatSoft 2008-2010

[Setup]
AppName=PlaatStats
AppVerName=PlaatSoft Downloads Statistics v0.70
DefaultDirName={pf}\PlaatStats
DefaultGroupName=PlaatSoft
UninstallDisplayIcon={app}\Statistics.exe
Compression=lzma
SolidCompression=yes
OutputDir=release\

[Files]
Source: "src\release\Statistics.exe"; DestDir: "{app}"
Source: "src\release\libgcc_s_dw2-1.dll"; DestDir: "{app}"
Source: "src\release\mingwm10.dll"; DestDir: "{app}"
Source: "src\release\QtCore4.dll"; DestDir: "{app}"
Source: "src\release\QtGui4.dll"; DestDir: "{app}"
Source: "src\release\QtNetwork4.dll"; DestDir: "{app}"
Source: "src\release\license.txt"; DestDir: "{app}"; Flags: isreadme

[Icons]
Name: "{group}\PlaatStats\PlaatStats"; Filename: "{app}\Statistics.exe"
Name: "{commondesktop}\PlaatSoft Statistics"; Filename: "{app}\Statistics.exe"
Name: "{group}\PlaatStats\Uninstaller"; Filename: "{uninstallexe}"
