(function($) {
Drupal.behaviors.myBehavior = {
  attach: function (context) {
    $(document).ready(function(){
      $(".new-window").offset({top: $(".new-mask").outerHeight()/2 - 100, left: $(".new-mask").outerWidth()/2 - 250});

      $('.new-title-button').click(function(){
        $('.custom-template-wrapper').hide();
      });

      $('.new-mask').click(function(){
        $('.custom-template-wrapper').hide();
      });

      $( function() {
        $('.new-window').draggable({ cancel: ".ui-widget-header" }, { containment: ".new-mask", scroll: false });
      });
    });
  }
 };
})(jQuery);