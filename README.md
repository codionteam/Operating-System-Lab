<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<title>YouTube Buttons</title>

<style>
  body {
    margin: 0;
    padding: 0;
    background-color: #ff0000; /* Full red background */
    height: 100vh;
  }

  .top-center {
    display: flex;
    justify-content: center;
    align-items: flex-start;
    padding-top: 30px; /* top space */
    gap: 20px;
  }

  .btn {
    padding: 14px 26px;
    font-size: 16px;
    font-weight: bold;
    text-decoration: none;
    color: white;
    border-radius: 10px;
    background-color: #b30000;
    transition: 0.3s;
    box-shadow: 0 6px 15px rgba(0,0,0,0.3);
  }

  .btn:hover {
    background-color: #800000;
    transform: scale(1.08);
  }
</style>
</head>

<body>

<div class="top-center">

  <a class="btn"
     href="https://youtu.be/K4hHWVif_wg?si=uEddzYRFUqtrwQAc"
     target="_blank">
     ▶ Watch Video
  </a>

  <a class="btn"
     href="https://www.youtube.com/@YourChannelName?sub_confirmation=1"
     target="_blank">
     🔔 Subscribe
  </a>

</div>

</body>
</html>
