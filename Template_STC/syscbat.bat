@echo off

set /p COMMIT_MSG=请输入commit消息：
set REPO_URL=https://github.com/your-username/your-repo.git
set PROJECT_FOLDER=.\project-folder

echo ======= Starting GitHub Sync =======
cd %PROJECT_FOLDER%
git init
git add .
git commit -m "%COMMIT_MSG%"
git remote add origin %REPO_URL%
git push -u origin master

echo ======= Sync Complete =======
pause