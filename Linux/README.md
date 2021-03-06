# OpenSiv3D Linux版について
諸事情により実装を見送っている機能を除くと、現在のバージョンは0.17.1900相当です。

## 導入手順
OpenSiv3D Linux版をビルドしてアプリケーションを作成するまでの手順を[こちら](INSTALL.md)にまとめてあります。

## サポート環境
サポートしているディスプレイサーバはX11のみです。
`CMakeLists.txt`にWaylandとMir向けにコンパイルするオプションがありますが、
サポートはしておりませんのでご注意ください。

## 依存ライブラリ・パッケージ
コンパイルと実行には以下のライブラリやパッケージが必要です。
- CMake 2.8 以上
- Clang 5, LLVM または GCC 7.2.0 以上
  - 開発にはClang 5とLLVMを使っています
  - CMakeLists.txt を編集すればGCCをコンパイラに指定できます
  - C++17に対応しているGCC 7.1.0 でもコンパイルできるかもしれません（未確認）
- boost
  - 必要なboostのバージョンについては `OpenSiv3D/Dependencies/README.md` を参照してください。
- glib2
- OpenGL
- GLU
- GLEW
- libpng
- turbojpeg
- X11
- X11 Input extension (Xi)
- X11 RandR extension (Xrandr)
- X11 Xinerama extension (Xinerama)
- X11 cursor management library (XCursor)
- FreeType2
- OpenAL


## 現状のOpenSiv3D Windows/macOS版との相違点
- Cursor::ScreenPos()とCursor::PreviousScreenPos()はそれぞれCursor::Pos()とCursor::PreviousPos()と同じ値を返します。(Linuxではディスプレイマネージャによって画面上のどこにカーソルがあるか取得する機能があったりなかったりするため。)
- Monitor::workAreaはMonitor::displayRectと同じ値になっています。(X11環境で各モニタのワークエリアを取得するのが難しいため。)
- Cursor::ClipClientRect()は動作しますが、clipする領域が黒で塗りつぶされます。(clip領域として指定するのに使っているWindowを透明に描画するするコードが上手く動かないため。)対策が分かり次第修正予定です。
- リソースファイルは実行ファイルと同階層の「resource」ディレクトリ内に配置されます。

