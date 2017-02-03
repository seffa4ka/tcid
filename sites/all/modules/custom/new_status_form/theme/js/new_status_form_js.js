(function($) {
Drupal.behaviors.new_status = {
  attach: function (context) {
    $(document).ready(function(){
        
      if (Drupal.settings.new_status.form_heidth !== null && Drupal.settings.new_status.form_width !== null){
        var form_h = Drupal.settings.new_status.form_heidth;
        var form_w = Drupal.settings.new_status.form_width;
      }
      else {
        var form_h = 200;
        var form_w = 500;
      }
      
      $(".new-window").height(form_h);
      
      $(".new-window").width(form_w);
      
      $(".new-window").offset({top: $(".new-mask").outerHeight()/2 - form_h/2, left: $(".new-mask").outerWidth()/2 - form_w/2});

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