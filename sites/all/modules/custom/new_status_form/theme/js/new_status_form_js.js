/**
 * @file
 * JS file.
 */

(function ($) {
Drupal.behaviors.new_status = {
  attach: function (context) {
    $(document).ready(function () {

      if (Drupal.settings.new_status.form_height !== null) {
        var form_h = Drupal.settings.new_status.form_height;
      }
      else {
        var form_h = 200;
      }

      if (Drupal.settings.new_status.form_width !== null) {
        var form_w = Drupal.settings.new_status.form_width;
      }
      else {
        var form_w = 500;
      }

      if (Drupal.settings.new_status.form_bg !== null) {
        var form_bg = Drupal.settings.new_status.form_bg;
      }
      else {
        var form_bg = "burlywood";
      }

      $(".new-window").height(form_h);

      $(".new-window").width(form_w);

      $(".new-body").css("background-color", form_bg);

      $(".new-window").offset({top: $(".new-mask").outerHeight() / 2 - form_h / 2, left: $(".new-mask").outerWidth() / 2 - form_w / 2});

      $('.new-title-button').click(function () {
        $('.custom-template-wrapper').hide();
      });

      $('.new-mask').click(function () {
        $('.custom-template-wrapper').hide();
      });

      $(function () {
        $('.new-window').draggable({ cancel: ".ui-widget-header" }, { containment: ".new-mask", scroll: false });
      });
    });
  }
 };
})(jQuery);
