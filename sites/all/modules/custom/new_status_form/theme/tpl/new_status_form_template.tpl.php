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
      <button class="new-title-button">X</button>
    </div>
    <div class="new-body">
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
