3RVX Changelog
==============

Beta 11 (2.9.3)
---------------
* Brightness OSD
* Keyboard OSD: Caps, Num, and Scroll lock; media keys
* Toggles for OSDs and their respective tray icons
* First-run setup prompt
* Default hotkey settings
* New French translation by xhark (https://twitter.com/xhark)
* Mute OSD now supports volume meters (text, bars, etc; level will be 0)
* New meter for OSDs: Slider knob (similar to volume slider)
* Skin color transformations (change #FF00FF to a user-defined accent color)
* New skin: Windows 8/10 OSD
* Option to view release notes in updater menu
* Bugfix: cleanly remove eject icon on shutdown
* Bugfix: thread hang on settings reload
* Bugfix: allow volume increments less than 1 [#55]
* Bugfix: invisible eject icon after settings reload
* Bugfix: COM object memory leak [#60, #59]

Beta 10 (2.9.2)
---------------
* Custom volume curves
* Custom volume limits
* Ability to force a volume limit on other applications
* Customizable default audio device (instead of always using the system default)
* Option to mute the volume on session lock [#48]
* Eject notification icon
* Detailed error messages
* Bugfix: Hotkey argument range validation
* Bugfix: Changing the volume slider while muted now unmutes the volume
* Bugfix: Display changes are monitored and accounted for (multi-monitor setups) [#36]
* Bugfix: Intermittent optical disk eject failure [#37]
* Bugfix: Null device crash [#42, #45]
* Bugfix: Updates launched from the settings app didn't shut down 3RVX

Beta 9 (2.9.1)
------
* Automatic updates
* Compatiblity mode for the old (v2) skin format
* Skin fallback: resources that aren't found will be loaded from the default skin
* Hotkey to disable/enable the OSD 
* Option to disable the OSD when another application is full screen
* Option to disable the OSD when a DirectX application has exclusive control of the screen
* Option to not show the volume OSD on startup
* Preliminary 64 bit support
* Bugfix: Translate 'Muted' for the notification icon
* Bugfix: Settings dialog is now re-translated on 'Apply'
* Bugfix: Settings not read if username contains non-ASCII characters
* Bugfix: Media keys in the hotkey list view are now translated properly

Beta 8
------
* Full screen detection
* UI Internationalization
* Items in the settings hotkey list now show parameters (e.g., Increase Volume 3%)
* Installer-based (non-portable) setup. Portable distributions will still be provided as well.
* Update checking functionality
* Launching multiple settings instances will now simply raise and activate the first instance
* Added content to the About tab
* New default notification area icon
* Bugfix: Corrupted "Run on Startup" registry entry
* Bugfix: Play sound for custom volume increments
* Bugfix: low-color icons were being loaded for the notification area

Beta 7
------
* Implement always on top toggle
* Completely overhauled settings UI backend - no more MFC
* If the settings file is missing or corrupted, defaults will be loaded automatically
* Fix volume state bug (switching devices didn't update volume state)
* Initial UI internationalization (language translation) functionality
* Update small glass skin to work with v3
* Custom volume hotkey increments: percentage and volume units
* 'Set Volume' hotkey
* 'Run' hotkey: open applications, folders, etc.

Beta 6
------
* Adds a new eject hotkey that ejects the most recently inserted drive
* Implements the 'Show Volume Slider' hotkey
* New slider controls: arrow keys and mouse wheel to change volume
* 'Natural' volume increment and decrement based on skin units
* Fix mute bug (external mute events did not show OSD)
* Allows shell hotkeys to be overridden (if desired)
* 'All Monitors' display option has been implemented
* Adds development option to log to file
* Media hotkey emulation

Beta 5
------
* Implements eject notification and hotkey functionality
* Disables glass on Windows 8 and up
* Respects animation setting (None, Fade)
* Respects animation speed setting
* Loads and applies skin sound effects
* Uses DirectShow for sound effects (reduces latency, improves responsiveness)
* Error messages while loading settings are more helpful

Beta 4
------
* Adds an option for skins to use Vista/Windows 7 glass via a mask
* Ki Shodar's Vista 808 skin has been ported to v3 (uses glass functionality)
* Allows selection of the display device (previously hardcoded to Primary display)
* Fixes several memory leaks and minor bugs
* Includes required DLLs in distribution

Beta 3
------
* Prevents OSD from displaying when an audio device reactivates

Beta 2
------
* Settings app now restarts 3RVX after apply/OK
* Fixed a bug that prevented 'extended keys' from being used in hotkey combinations
* Allow the notification icon to be disabled
* Prevent multiple settings dialogs from being opened

Beta 1
------
* Initial Release of 3RVX 3.0
