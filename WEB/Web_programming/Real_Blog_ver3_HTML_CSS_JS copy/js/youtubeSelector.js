
$(document).ready(function(){
  $("#grid>.yt").click(function(){
    $(".yt").hide();
    $(this).show();
    $(this).css({"width":"150%", "height":"100%"});
    $("section").css({"left":"20%"});
  });
});

// $(document).ready(function(){
//   $("#test").click(function(){
//     $("#grid>.yt").show();
//   });
// });