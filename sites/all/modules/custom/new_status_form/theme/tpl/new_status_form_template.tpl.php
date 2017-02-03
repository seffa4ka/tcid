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
  <div class="new-window ui-widget-content">
    <div class="new-title">
      <div class="new-title-message">New status form</div>
      <input class="new-title-button ui-widget-header" type="button" value="Х" />
    </div>
    <div class="new-body ui-widget-header">
      <?php
      foreach ($variables['body'] as $title => $messages) {
      ?>
        <?php
        if($title === 'status'){
        ?>
        <div class="new-status-messages">
          <?php
          foreach ($messages as $message) {
            echo $message . '<br>';
          }
          ?>
        </div>
        <?php
        }

        if($title === 'error'){
        ?>
        <div class="new-error-messages">
          <?php
          foreach ($messages as $message) {
            echo $message . '<br>';
          }
          ?>
        </div>
        <?php
        }

        if($title === 'warning'){
        ?>
        <div class="new-warning-messages">
          <?php
          foreach ($messages as $message) {
            echo $message . '<br>';
          }
          ?>
        </div>
        <?php
        }
        ?>
      <?php
      }
      ?>
    </div>
  </div>
</div>
