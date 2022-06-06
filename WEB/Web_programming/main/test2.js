$(document).ready(function () {
  $("button.b1").click(function () {
    $("img").animate({
      width: '100px'
    });
  });
  $("button.b2").click(function () {
    $("img").animate({
      width: '200px'
    });
  });
  $("button.b3").click(function () {
    $("img").animate({
      width: '300px'
    });
  });
});