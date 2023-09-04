@echo off
chcp 65001
setlocal enabledelayedexpansion

:menu
cls
echo ================== Git 管理工具 ==================
echo.
echo 1. 添加文件到暂存区
echo.
echo 2. 提交更改到本地仓库
echo.
echo 3. 推送更改到远程仓库
echo.
echo 4. 一键推送（添加文件到暂存区、提交更改到本地仓库、推送更改到远程仓库）
echo.
echo 5. 退出
echo.
echo =======================================================

set /p choice="请选择操作："

if "%choice%"=="1" (
    call :add_files
) else if "%choice%"=="2" (
    call :commit_files
) else if "%choice%"=="3" (
    call :push_files
) else if "%choice%"=="4" (
    call :one_key_push
) else if "%choice%"=="5" (
    goto :exit
) else (
    echo 无效的选择，请重新输入.
    pause
    goto :menu
)

:add_files
echo.
echo 正在添加文件到暂存区...

git add .
echo.
echo 文件已成功添加到暂存区.
goto :eof

:commit_files
echo.
echo 正在提交更改到本地仓库...

set /p commit_message="请输入提交消息: "
if "%commit_message%"=="" (
    echo 未输入提交消息，请重新输入.
    goto :commit_files
) else (
    git commit -m "%commit_message%"
    echo.
    echo 更改已成功提交到本地仓库.
    goto :eof
)

:push_files
echo.
echo 正在推送更改到远程仓库...

git branch > branch_list.txt
echo.

set branch_options=""
for /f "tokens=1" %%i in (branch_list.txt) do (
    set branch_options=!branch_options! %%i
    echo %%i
)

set /p branch_name="请选择或输入分支名称 [%branch_options%]: "

if "%branch_name%"=="" (
    echo 未选择或输入分支名称，请重新输入.
    goto :push_files
)

git branch | findstr /i /c:"%branch_name%"
if %errorlevel%==1 (
    set /p create_new_branch="分支 %branch_name% 不存在，是否创建新分支？ [Y/N]: "
    if /i "%create_new_branch%"=="Y" (
        git checkout -b %branch_name%
        echo.
        echo 分支 %branch_name% 创建成功.
    ) else (
        echo 未创建新分支.
        goto :push_files
    )
)
git push origin %branch_name%
echo.
echo 更改已成功推送到远程仓库的分支 %branch_name%.
pause
goto :eof

:one_key_push
echo.
echo 正在执行一键推送...

call :add_files
call :commit_files
call :push_files

pause
goto :eof

:exit
exit /b