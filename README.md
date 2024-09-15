This is a basic mediaplayer made by QT. It is created for testing the difficulty of QT and configuration. 

Basic Development Information
-
1. Language: C++
2. Application：QT creator. 
3. Version: Qt 6.7.2 (MSVC 2019, x86_64). Built on Aug 6 2024 00:17:40. (not the LST one)
4. The build tools of QT<br>
-cmaker (hard to cconfigure)<br>
-qmaker (easier to configure)

Currently Implemented Features
-
1. Display Image
3. Playing & Pausing Video
4. Dragging Progress Bar
5. Dragging Volume Bar
6. Muted
7. Display Average FrameRate

Configuration files that have been tried
1. OpenGL (Image Rendering)<br>
-cmaker(succeed, a little bit hard)<br>
-qmaker(succeed, very easy, no need to download additional files)
2. FFmpeg (Image Decoding)<br>
-cmaker(failed)<br>
-qmaker(succeed, need to download ffmpeg-full-shared-version)

*Theoretically, FFmpeg and OpenGL can achieve video at 1,000 fps and 100,000 pixels. QT's built-in components cannot do this.
