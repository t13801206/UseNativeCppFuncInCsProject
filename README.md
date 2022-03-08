# UseNativeCppFuncInCsProject

C#からC++ネイティブ関数をコールする2つの方法

- 方法1: C++/CLIラッパー
- 方法2: DllImport

## 概要

- C++は`OpenCV 4.3.0`を使う
- C#は`x86`/`x64`の2つの構成に対応する

## 対象プラットフォームごとの出力先

プロジェクト|フレームワーク|ビルド|出力先
-|-|-|-
CsMainUser|.NET Framework 4.6.1|`AnyCpu`/`x86`|UseNativeCppFuncInCsProject\Debug
CsMainUser|.NET Framework 4.6.1|`x64`|UseNativeCppFuncInCsProject\x64\Debug
CppUserConsole_dotnetdore31|.NET Core 3.1|`x86`|UseNativeCppFuncInCsProject\Debug\netcoreapp3.1
CppUserConsole_dotnetdore31|.NET Core 3.1|`AnyCpu`/`x64`|UseNativeCppFuncInCsProject\x64\Debug\netcoreapp3.1

.NET Core 3.1プロジェクトの`AnyCpu`は「32bitを選ぶ（優先する）」にチェックは入れていない

## ビルドの依存関係

- CsMainUser → WrapperClass → NativeFunc
- CppUserConsole_dotnetdore31 → CppNativeForDotnetCore31

## 追加の依存ファイル

リンカー／入力／追加の依存ファイル

```text
opencv_calib3d430d.lib
opencv_core430d.lib
opencv_dnn430d.lib
opencv_features2d430d.lib
opencv_flann430d.lib
opencv_gapi430d.lib
opencv_highgui430d.lib
opencv_imgcodecs430d.lib
opencv_imgproc430d.lib
opencv_ml430d.lib
opencv_objdetect430d.lib
opencv_photo430d.lib
opencv_stitching430d.lib
opencv_video430d.lib
opencv_videoio430d.lib
```

## 追加のライブラリディレクトリ

リンカー／全般／追加のライブラリディレクトリ

プラットフォーム|追加のライブラリディレクトリ
-|-
`Win32`|opencv-4.3.0\build32bit\install\x86\vc14\lib
`x64`|opencv-4.3.0\build\install\x64\vc15\lib

## 追加のインクルードディレクトリ

C/C++／全般／追加のインクルードディレクトリ

プラットフォーム|追加のライブラリディレクトリ
-|-
`Win32`|  opencv-4.3.0\build32bit\install\include
`x64`|opencv-4.3.0\build\install\include

## システム環境変数

`.dll`ファイルが格納されているフォルダーにパスを通す

システム環境変数の変更を反映するために、**OSを再起動する**

- **\opencv-4.3.0\build32bit\install\x86\vc14\bin**
  - 32bit
  - build by Visual Studio 2015 Community
- **\opencv-4.3.0\build\install\x64\vc15\bin**
  - 64bit
  - build by Visual Studio 2017 Community

## トラブルシューティング

エラー発生タイミング|エラーメッセージ|対応
-|-|-
ビルド時|外部シンボル XXX は未解決です|リンカー／入力／追加の依存ファイルが不足している
実行時|xxxxx.dll'、またはその依存関係の一つが読み込めませんでした|環境変数に.dllのパスを通す
実行時|間違ったフォーマットのプログラムを読み込もうとしました|`AnyCpu`,`x64`/`x86`それぞれの構成が正しいことを確認する。また実行ファイル`.exe`/`.dll`の出力先が正しいことを確認する

## 参考サイト

- [OpenCV_32bit版の環境構築手順](https://bluebirdofoz.hatenablog.com/entry/2019/10/26/200208)
- [（04）C#から、C++の関数の実行（クラス）](https://waku-take-a.github.io/Programming.html)
- [C#からC/C++の関数をコールする方法　まとめ①](https://qiita.com/TackKaiware/items/27ebcf10bb2624db197a)
- [OpenCVをVisual Studio 2019でビルド](https://blog.goo.ne.jp/yoossh/e/fe038fc38cf3b276f626a421ca927fe4)