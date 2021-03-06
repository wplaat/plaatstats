/**
 *  @file
 *  @brief The file contain the statistics windows
 *  @author wplaat
 *
 *  Copyright (C) 2008-2012 PlaatSoft
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef STATS_H
#define STATS_H

#include <QMainWindow>
#include <QtNetwork>

#include "settings.h"
#include "about.h"
#include "donate.h"

#define VERSION  "1.1"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionDonate_triggered();
    void on_actionCheck_for_update_triggered();
    void on_actionSettings_triggered();
    void showAbout();
    void fetchData();
    void replyFinished(QNetworkReply*);
    void fillClipboard();

protected:
    void changeEvent(QEvent *e);

private:
    void createActions();
    void stateMachine();
    const char *getDate();
    int convert(QString number);
    QString formatNumber(int number);
    QString formatNumber(QString number);

    Settings settings;
    About about;
    Donate donate;

    void calculate();

    void calculateWiiApplTotals();
    void calculateWiiMyWebsite();
    void calculateWiiHomebrewBrowser();
    void calculateWiiGoogleCode();
    void calculateWiiTotals();

    void calculateDrupalMyWebsite();
    void calculateDrupalGoogleCode();
    void calculateDrupalTotals();

    void calculateWindowsMyWebsite();
    void calculateWindowsGoogleCode();
    void calculateWindowsTotals();

    void fetchVersion();
    void closeEvent(QCloseEvent *event);
    void readSettings();
    void writeSettings();
    void parseVersion(QString response);
    int  parseGoogleCodePage(QString result);

    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QString result;
    int sm;

    QAction *fetchAct;
};

#endif // STATS_H

/**
 * @mainpage PlaatStats Documentation
 * Welcome to the PlaatStats documentation.
 *
 * @section Introduction
 * PlaatStats is Windows Statistics tool
 *
 * @section Links
 * Website: http://www.plaatsoft.nl\n
 * Code: http://code.google.com/p/plaatstats\n
 *
 * @section Credits
 * Documentation: wplaat\n
 *
 * @section WishList
 * - Http proxy support
 *
 * @section ReleaseNotes
 *
 *  <b>09-07-2012 Version 1.1</b>
 *  - Correct www.plaatsoft.nl url
 *  - KnightsQuest Windows data fetching corrected!
 *  - Use QT library 4.8.0 as engine.
 *  - PlaatStats is build with QtCreator v2.4.1
 *
 *  <b>11-10-2011 Version 1.0</b>
 *  - BugFix: Enlarge Windows RedSquare counter size.
 *  - Added QT version number on about window.
 *  - Use QT library 4.7.4 as engine.
 *  - PlaatStats is build with QtCreator v2.3.0
 *
 *  <b>23-03-2011 Version 0.90</b>
 *  - Added WarQuest for Windows statistics.
 *  - Added ChatCostCalc for Windows statistics.
 *  - Enlarge Windows RedSquare counter
 *  - Update google code page download analyser.
 *  - Improve "Data to clipboard" functionality.
 *  - PlaatStats is build with QtCreator v2.0.0
 *
 *  <b>02-10-2010 Version 0.80</b>
 *  - Added KnightQuest game for Nintendo Wii and Windows
 *  - Added in clipboard export Windows tools and games.
 *  - Maintenance Release.
 *  - Use Qt library 4.7.0 as engine.
 *  - PlaatStats is build with QtCreator v2.0.0
 *
 *  <b>14-05-2010 Version 0.70</b>
 *  - Disable main window when sub window is opened.
 *  - Improve new version check.
 *  - Added donate window.
 *  - Added Drupal Google Code downloads to statistics.
 *  - Bugfix: Drupal ChurchAdmin module is now also counted.
 *  - PlaatStats is build with QtCreator v1.3.1.
 *
 *  <b>29-03-2010 Version 0.60</b>
 *  - Rename registry key names.
 *  - Improve source code documentation.
 *  - Improve about window (Add plaatsoft logo).
 *  - Added settings window.
 *  - Added support for http proxy.
 *  - Added new version check.
 *  - PlaatStats is build with QtCreator v1.3.1.
 *
 *  <b>21-03-2010 Version 0.50</b>
 *  - Improve number layout (dot notation after 3 digits).
 *  - Add Windows setup file.
 *  - Add source code to Google Code
 *  - PlaatStats is build with QtCreator v1.3.1.
 *
 *  <b>18-03-2010 Version 0.40</b>
 *  - Change GUI layout.
 *  - Added Drupal downloads.
 *  - Added application icon.
 *  - Refactor file names.
 *  - PlaatStats is build with QtCreator v1.3.1
 *
 *  <b>17-03-2010 Version 0.30</b>
 *  - First release for Homebrew Scene.
 *  - Cleanup code.
 *  - If internet is down show 0 values in boxes.
 *  - Move clipboard functionality to Menu action.
 *  - PlaatStats is build with QtCreator v1.3.1
 *
 *  <b>16-03-2010 Version 0.20</b>
 *  - Added fix window size.
 *  - Store window position in Windows registry.
 *  - Improve GUI layout.
 *  - Fetch data from Google Code sites.
 *  - When application is started, information is directly fetched.
 *  - Add windows clipboard support (HTML output is added)
 *  - PlaatStats is build with QtCreator v1.3.1
 *
 *  <b>14-03-2010 Version 0.10</b>
 *  - Start building.
 *  - Created GUI.
 *  - Added network call (Plaatsoft and CodeMii website)
 *  - Added stateMachine.
 *  - PlaatStats is build with QtCreator v1.3.1
 */
