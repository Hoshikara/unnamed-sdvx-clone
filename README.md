# [Download](https://drive.google.com/file/d/1LBB7s8W-BZ8qVh4wkw8XiY0OgKB9Y54t/view?usp=sharing)

# FOLLOW THE INSTRUCTIONS INSIDE `SKINS/SKIN_PATCH` AFTER DOWNLOADING

A fork to build a version of USC without the laser changes implemented around April 2021. There has been some work to cherry-pick commits from USC's `develop` branch with a few omissions (see commit history of the `personal` branch).

Some extra changes made with no oversight so be aware:
- Laser assist *configurability* has been removed, the default values have been hard-coded
- IR has been disabled for leaderboard integrity
- Modified camera behavior to be more similar to EG:
  - Automatic pre-tilt from upcoming lasers removed
  - Slams do not apply roll
  - Rolls are done at a constant speed
- Separate textures for hit beams, with a new state for hits that are within half of your critical window (think S-CRITICAL)
- Lane-speed will automatically scale up inversely to song speed during Practice Mode (only tested with MMOD)
