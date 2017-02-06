<?php

/**
 * @file
 * Theme.
 *
 * New status form theme.
 */
?>
<div class="custom-template-wrapper">
  <div class="new-mask"></div>
  <div class="new-window">
    <div class="new-title">
      <div class="new-title-message">New status form</div>
      <input class="new-title-button" type="button" value="Х" />
    </div>
    <div class="new-body ui-widget-header">
      <?php
        echo $variables['body'];
      ?>
    </div>
  </div>
</div>
