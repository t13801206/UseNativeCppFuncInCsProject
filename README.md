# UseNativeCppFuncInCsProject

C#からC++ネイティブを使う方法

## 概要

- OpenCV4.3をC++ネイティブで作成し、CLIラッパーを通してC#で使う
- C#はx86/x64の2つの構成に対応す
- 32bitプロセスで動かす必要があるライブラリを使う場合、AnyCpuで構成する

- ## 出力先

x86:UseNativeCppFuncInCsProject\Debug
x64:UseNativeCppFuncInCsProject\x64\Debug

## 依存関係

CsMainUser->WrapperClass->NativeFunc

## システム環境変数

システム環境変数の変更は、再起動後に反映される

- **\opencv-4.3.0\build32bit\install\x86\vc14\bin**
  - 32bit
  - build by Visual Studio 2015 Community
- **\opencv-4.3.0\build\install\x64\vc15\bin**
  - 64bit
  - build by Visual Studio 2017 Community

## 参考サイト

- [OpenCV_32bit版の環境構築手順](https://bluebirdofoz.hatenablog.com/entry/2019/10/26/200208)
- [（04）C#から、C++の関数の実行（クラス）](https://waku-take-a.github.io/Programming.html)
