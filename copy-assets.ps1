# copy-assets.ps1 — Run this once to copy project images into the repo
$src = "C:\Users\vivek\Desktop\vivekv-site\assets\images"
$repoImg = "C:\Users\vivek\Desktop\gesture-controlled-robotic-arm\docs\images"

New-Item -ItemType Directory -Force -Path $repoImg | Out-Null

Copy-Item "$src\hand-gesture\gesture-glove.png"         "$repoImg\gesture-glove.png"         -Force
Copy-Item "$src\hand-gesture\hand-gesture-800.png"      "$repoImg\arm-and-glove.png"          -Force
Copy-Item "$src\hand-gesture\hand-gesture-electronics.jpg" "$repoImg\electronics-overview.jpg" -Force
Copy-Item "$src\robotic-arm\robotic-arm-assembly.jpg"   "$repoImg\robotic-arm-assembly.jpg"   -Force

# Also copy the demo video
$videoSrc = "C:\Users\vivek\Pictures\Linkdin stuff\posts\post 3\project 1.mp4"
$videoDst = "C:\Users\vivek\Desktop\gesture-controlled-robotic-arm\docs\demo.mp4"
Copy-Item $videoSrc $videoDst -Force

Write-Host "All assets copied successfully!"
