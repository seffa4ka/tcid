/**
 * @file
 * JS file.
 */

(function ($) {
Drupal.behaviors.new_status = {
  attach: function (context, settings) {
    $(document).ready(function () {

      var window = $('.new-window');
      var mask = $('.new-mask');
      var wrapper = $('.custom-template-wrapper')

      if (settings.new_status.form_height !== null) {
        var form_h = settings.new_status.form_height;
      }
      else {
        var form_h = 200;
      }

      if (settings.new_status.form_width !== null) {
        var form_w = settings.new_status.form_width;
      }
      else {
        var form_w = 500;
      }

      if (settings.new_status.form_bg !== null) {
        var form_bg = settings.new_status.form_bg;
      }
      else {
        var form_bg = 'burlywood';
      }

      window.height(form_h);

      window.width(form_w);

      $('.new-body').css('background-color', form_bg);

      window.offset({top: mask.outerHeight() / 2 - form_h / 2, left: mask.outerWidth() / 2 - form_w / 2});

      $('.new-title-button').click(function () {
        wrapper.hide();
      });

      mask.click(function () {
        wrapper.hide();
      });

      $(function () {
        window.draggable({ cancel: '.ui-widget-header' }, { containment: '.new-mask', scroll: false });
      });
    });
  }
 };
})(jQuery);
